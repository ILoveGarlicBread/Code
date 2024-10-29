#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        exit(1);
    }

    // Shared memory setup
    struct timeval *shared_time = mmap(NULL, sizeof(struct timeval), 
                                       PROT_READ | PROT_WRITE, 
                                       MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (shared_time == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    
    if (pid == 0) {  // Child process
        gettimeofday(shared_time, NULL);  // Record starting time
        execvp(argv[1], &argv[1]);
        perror("execvp");  // execvp failed
        exit(1);
    } else {  // Parent process
        struct timeval end_time;
        wait(NULL);  // Wait for child to complete
        gettimeofday(&end_time, NULL);  // Record end time

        double elapsed = (end_time.tv_sec - shared_time->tv_sec) +
                         (end_time.tv_usec - shared_time->tv_usec) / 1e6;
        printf("Elapsed time: %.5f seconds\n", elapsed);

        // Clean up shared memory
        munmap(shared_time, sizeof(struct timeval));
    }

    return 0;
}

