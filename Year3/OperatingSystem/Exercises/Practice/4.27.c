#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int *fibo_sequence;
int n;

void *fibo_gen(void *arg) {
  fibo_sequence[0] = 0;
  if (n > 1) {
    fibo_sequence[1] = 1;
    for (int i = 2; i < n; i++) {
      fibo_sequence[i] = fibo_sequence[i - 1] + fibo_sequence[i - 2];
    }
  }
  pthread_exit(NULL);
}

int main() {
  printf("Input a number to generate fibo: ");
  scanf("%d", &n);
  fibo_sequence = (int *)malloc(sizeof(int));
  pthread_t thread;
  pthread_create(&thread, NULL, fibo_gen, NULL);
  pthread_join(thread, NULL);
  printf("Result: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", fibo_sequence[i]);
  }
  printf("\n");
  free(fibo_sequence);
}
