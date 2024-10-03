
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int *fibo_sequence;
int n;
int current_index;
pthread_mutex_t mutex;
pthread_cond_t condition;

void *fibo_gen(void *arg) {
  fibo_sequence[0] = 0;
  pthread_mutex_lock(&mutex);
  current_index = 1;
  pthread_cond_signal(&condition);
  pthread_mutex_unlock(&mutex);
  if (n > 1) {
    pthread_mutex_lock(&mutex);
    current_index = 2;
    pthread_cond_signal(&condition);
    pthread_mutex_unlock(&mutex);
    fibo_sequence[1] = 1;
    for (int i = 2; i < n; i++) {
      fibo_sequence[i] = fibo_sequence[i - 1] + fibo_sequence[i - 2];
      pthread_mutex_lock(&mutex);
      current_index = i + 1;
      pthread_cond_signal(&condition);
      pthread_mutex_unlock(&mutex);
    }
  }
  pthread_exit(NULL);
}

int main() {
  printf("Input a number to generate fibo: ");
  scanf("%d", &n);
  fibo_sequence = (int *)malloc(n * sizeof(int));
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&condition, NULL);
  pthread_t thread;
  pthread_create(&thread, NULL, fibo_gen, NULL);
  printf("Result: ");
  for (int i = 0; i < n; i++) {
    pthread_mutex_lock(&mutex);
    while (current_index <= 1) {
      pthread_cond_wait(&condition, &mutex);
    }
    printf("%d ", fibo_sequence[i]);
    pthread_mutex_unlock(&mutex);
  }
  printf("\n");
  pthread_join(thread, NULL);
  free(fibo_sequence);
  pthread_cond_destroy(&condition);
  pthread_mutex_destroy(&mutex);
}
