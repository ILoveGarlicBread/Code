#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#define SHM_NAME "collatz_shm"
#define SHM_SIZE 4096

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <positive number>\n", argv[0]);
    exit(1);
  }
  int n = atoi(argv[1]);
  if (n <= 0) {
    fprintf(stderr, "Error: not positive integer.");
    exit(1);
  }
  int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
  if (shm_fd < 0) {
    perror("shm_open failed.");
    exit(1);
  }
  if (ftruncate(shm_fd, SHM_SIZE) == -1) {
    perror("ftruncate failed.");
    exit(1);
  }
  char *shm_ptr =
      mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
  if (shm_ptr == MAP_FAILED) {
    perror("mmap failed");
    return 1;
  }
  memset(shm_ptr, 0, SHM_SIZE);
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(1);
  }
  if (pid == 0) {
    int writePosition = 0;
    while (n != 1) {
      writePosition +=
          snprintf(shm_ptr + writePosition, SHM_SIZE - writePosition, "%d ", n);
      if (n % 2 == 0) {
        n = n / 2;
      } else {
        n = 3 * n + 1;
      }
    }
    writePosition +=
        snprintf(shm_ptr + writePosition, SHM_SIZE - writePosition, "%d ", n);
    exit(1);

  } else {
    wait(NULL);
    printf("Collatz sequence: %s\n", shm_ptr);
  }

  shm_unlink(SHM_NAME);
  return 0;
}
