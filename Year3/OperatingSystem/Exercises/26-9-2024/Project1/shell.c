#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h> 

#define MAX_LINE 80       /* The maximum length command */
#define MAX_COMMANDS 10   /* Maximum number of piped commands */

/* Function to parse the input line into separate commands based on pipes */
int parse_commands(char *input, char **commands) {
    int count = 0;
    char *token = strtok(input, "|");
    while (token != NULL && count < MAX_COMMANDS) {
        // Trim leading and trailing whitespace
        while (*token == ' ') token++;  // Leading spaces
        char *end = token + strlen(token) - 1;
        while (end > token && (*end == ' ' || *end == '\t')) {
            *end = '\0';
            end--;
        }
        commands[count++] = token;
        token = strtok(NULL, "|");
    }
    commands[count] = NULL;  // Null-terminate the array
    return count;
}

int main(void) {
    char *args[MAX_LINE / 2 + 1];      /* Command line arguments */
    char input[MAX_LINE];             
    char last_command[MAX_LINE] = "";  
    int should_run = 1;                /* Flag to determine when to exit program */

    while (should_run) {
        printf(":zsh> ");
        fflush(stdout);

        if (fgets(input, MAX_LINE, stdin) == NULL) {
            // Handle EOF (e.g., Ctrl+D)
            printf("\n");
            break;
        }

        // Remove the newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Check if the input is "!!"
        if (strcmp(input, "!!") == 0) {
            if (strlen(last_command) == 0) {
                fprintf(stderr, "No commands in history.\n");
                continue; // Prompt again
            } else {
                printf("%s\n", last_command); // Display the last command
                strncpy(input, last_command, MAX_LINE);
                input[MAX_LINE - 1] = '\0'; // Ensure null-termination
            }
        } else {
            // If the command is not "!!" and not empty, store it as the last command
            if (strlen(input) > 0) {
                strncpy(last_command, input, MAX_LINE);
                last_command[MAX_LINE - 1] = '\0'; // Ensure null-termination
            }
        }

        // Parse the input into separate commands based on pipes
        char *commands[MAX_COMMANDS + 1]; // +1 for NULL terminator
        int num_commands = parse_commands(input, commands);

        if (num_commands == 0) {
            continue; // No commands to execute
        }

        // Check if the last command ends with '&' for background execution
        int background = 0;
        char *last_cmd = commands[num_commands - 1];
        int last_cmd_len = strlen(last_cmd);
        if (last_cmd_len > 0 && last_cmd[last_cmd_len - 1] == '&') {
            background = 1;
            last_cmd[last_cmd_len - 1] = '\0'; // Remove '&' from command
            // Trim trailing spaces after removing '&'
            while (last_cmd_len > 1 && (last_cmd[last_cmd_len - 2] == ' ' || last_cmd[last_cmd_len - 2] == '\t')) {
                last_cmd[last_cmd_len - 2] = '\0';
                last_cmd_len--;
            }
        }

        int i;
        int in_fd = STDIN_FILENO; // Initially, input is from standard input

        pid_t pid;
        int status;
        int fd[2];

        for (i = 0; i < num_commands; i++) {
            // Parse arguments for the current command
            char *args_inner[MAX_LINE / 2 + 1];
            int arg_count = 0;
            char *token = strtok(commands[i], " ");
            while (token != NULL && arg_count < (MAX_LINE / 2)) {
                args_inner[arg_count++] = token;
                token = strtok(NULL, " ");
            }
            args_inner[arg_count] = NULL; // Null-terminate the array

            if (args_inner[0] == NULL) {
                // Empty command, skip
                continue;
            }

            /* Check if user wants to exit */
            if (strcmp(args_inner[0], "exit") == 0) {
                should_run = 0;
                break;
            }

            /* Initialize redirection variables */
            char *input_file = NULL;
            char *output_file = NULL;

            /* Check for redirection symbols within the current command */
            int j;
            for (j = 0; args_inner[j] != NULL; j++) {
                if (strcmp(args_inner[j], "<") == 0) {
                    if (args_inner[j + 1] != NULL) {
                        input_file = args_inner[j + 1];
                        args_inner[j] = NULL; // Terminate args at '<'
                        break;
                    } else {
                        fprintf(stderr, "Error: No input file specified after '<'\n");
                        input_file = NULL;
                        break;
                    }
                } else if (strcmp(args_inner[j], ">") == 0) {
                    if (args_inner[j + 1] != NULL) {
                        output_file = args_inner[j + 1];
                        args_inner[j] = NULL; // Terminate args at '>'
                        break;
                    } else {
                        fprintf(stderr, "Error: No output file specified after '>'\n");
                        output_file = NULL;
                        break;
                    }
                }
            }

            // If not the last command, create a pipe
            if (i < num_commands - 1) {
                if (pipe(fd) < 0) {
                    perror("pipe");
                    exit(EXIT_FAILURE);
                }
            }

            pid = fork();

            if (pid < 0) {
                perror("Fork failed");
                exit(EXIT_FAILURE);
            }
            else if (pid == 0) {  /* Child process */
                // Handle input redirection if present
                if (input_file != NULL) {
                    int fd_in = open(input_file, O_RDONLY);
                    if (fd_in < 0) {
                        perror("Error opening input file");
                        exit(EXIT_FAILURE);
                    }
                    if (dup2(fd_in, STDIN_FILENO) < 0) {
                        perror("Error duplicating file descriptor for input");
                        close(fd_in);
                        exit(EXIT_FAILURE);
                    }
                    close(fd_in);
                }
                else if (in_fd != STDIN_FILENO) {
                    // Redirect input from the previous pipe
                    if (dup2(in_fd, STDIN_FILENO) < 0) {
                        perror("Error duplicating file descriptor for input pipe");
                        exit(EXIT_FAILURE);
                    }
                    close(in_fd);
                }

                // Handle output redirection if present
                if (output_file != NULL) {
                    int fd_out = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
                    if (fd_out < 0) {
                        perror("Error opening/creating output file");
                        exit(EXIT_FAILURE);
                    }
                    if (dup2(fd_out, STDOUT_FILENO) < 0) {
                        perror("Error duplicating file descriptor for output");
                        close(fd_out);
                        exit(EXIT_FAILURE);
                    }
                    close(fd_out);
                }
                else if (i < num_commands - 1) {
                    // Redirect output to the next pipe
                    if (dup2(fd[1], STDOUT_FILENO) < 0) {
                        perror("Error duplicating file descriptor for output pipe");
                        exit(EXIT_FAILURE);

                    }
                    close(fd[1]);
                }

                // Close unused file descriptors in child
                if (fd[0] != 0)
                    close(fd[0]);
                if (fd[1] != 1)
                    close(fd[1]);

                /* Execute the command */
                if (execvp(args_inner[0], args_inner) < 0) {
                    fprintf(stderr, "Error executing command: %s\n", args_inner[0]);
                    exit(EXIT_FAILURE);
                }
            }
            else {  /* Parent process */
                // Close write end of the current pipe in the parent
                if (i < num_commands - 1)
                    close(fd[1]);

                // Close the previous read end if it's not standard input
                if (in_fd != STDIN_FILENO)
                    close(in_fd);

                // The read end of the current pipe becomes the input for the next command
                if (i < num_commands - 1)
                    in_fd = fd[0];
            }
        }

        // After forking all child processes, wait for them if not background
        if (!background) {
            for (i = 0; i < num_commands; i++) {
                wait(&status);
            }
        }
        // If background, do not wait and immediately prompt for next command
    }

    return 0;
}

