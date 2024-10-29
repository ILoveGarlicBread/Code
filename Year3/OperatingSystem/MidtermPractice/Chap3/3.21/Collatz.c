#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

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
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(1);
  }
  if (pid == 0) {
    while (n != 1) {
      printf("%d, ", n);
      if (n % 2 == 0) {
        n = n / 2;
      } else {
        n = 3 * n + 1;
      }
    }
    printf("1\n");
    exit(1);

  } else {
    wait(NULL);
  }

  return 0;
}
