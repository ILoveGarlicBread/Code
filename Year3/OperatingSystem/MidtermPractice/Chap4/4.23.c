#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *printPrime(void *param) {
  int n = *(int *)param;

  if (n <= 1) {
    printf("%d is not prime.\n", n);
    pthread_exit(0);
  }

  printf("1 ");
  for (int num = 2; num <= n; num++) {
    int isPrime = 1;

    for (int i = 2; i <= sqrt(num); i++) {
      if (num % i == 0) {
        isPrime = 0;
        break;
      }
    }

    if (isPrime) {
      printf("%d ", num);
    }
  }

  pthread_exit(0);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <positive integer>\n", argv[0]);
    exit(1);
  }

  int n = atoi(argv[1]);
  pthread_t primethread;

  pthread_create(&primethread, NULL, printPrime, &n);
  pthread_join(primethread, NULL);

  printf("\n");
  return 0;
}

