#include <stdio.h>
#include <unistd.h>
int main() {
  fork();
  fork();
  fork();
  printf("1\n");
  return 0;
}
