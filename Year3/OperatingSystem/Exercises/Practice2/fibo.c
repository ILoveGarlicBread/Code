#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#define SIZE 3
sem_t empty,full;
int buffer[SIZE];
int count;
int in, out;

void *generate_fibonacci(void *arg) {
  while (in < count) {
    sem_wait(&empty);
    if (in < 2)
      buffer[in] = 1;
    else
      buffer[in % SIZE] = buffer[(in - 1) % SIZE] + buffer[(in - 2) % SIZE];
    in++;
    sem_post(&full);
  }
}
int main() {
  printf("Enter number to generate fibo: ");
  scanf("%d", &count);
  in = 0;
  out = 0;
  sem_init(&empty,0,SIZE);
  sem_init(&full,0,0);

  pthread_t fibo_thread;
  pthread_create(&fibo_thread, NULL, generate_fibonacci, NULL);

  while (out < count) {
    sem_wait(&full);
    printf("%d ", buffer[out % SIZE]);
    out++;
    sem_post(&empty);
  }

  return 0;
}
