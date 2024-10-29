#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        exit(1);
    }

    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {  // Child process
        close(pipefd[0]);  // Close unused read end

        struct timeval start_time;
        gettimeofday(&start_time, NULL);  // Record starting time

        // Write start_time to pipe
        if (write(pipefd[1], &start_time, sizeof(start_time)) == -1) {
            perror("write");
            exit(1);
        }
        close(pipefd[1]);  // Close write end

        execvp(argv[1], &argv[1]);
        perror("execvp");  // execvp failed
        exit(1); // exit child
    } else {  // Parent process
        close(pipefd[1]);  // Close unused write end

        struct timeval start_time, end_time;
        if (read(pipefd[0], &start_time, sizeof(start_time)) == -1) {
            perror("read");
            exit(1);
        }
        close(pipefd[0]);  // Close read end

        wait(NULL);  // Wait for child to complete
        gettimeofday(&end_time, NULL);  // Record end time

        double elapsed = (end_time.tv_sec - start_time.tv_sec) +
                         (end_time.tv_usec - start_time.tv_usec) / 1e6;
        printf("Elapsed time: %.5f seconds\n", elapsed);
    }

    return 0;
}


