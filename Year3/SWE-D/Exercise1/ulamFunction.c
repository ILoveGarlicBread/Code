#include <stdio.h>

unsigned long long collatz(unsigned long long n) {
  while (n != 1) {
    if (n % 2 == 0)
      n /= 2;
    else
      n = 3 * n + 1;
  }
  return n;
}

int main() {
  for (int i = 1; i < 10000000; ++i) {
    if (collatz(i) != 1) {
      printf("Failed at %d\n", i);
      return 1;
    }
  }

  printf("Verified.\n");
  return 0;
}
