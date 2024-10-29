#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double average = 0.0;
int max = 0;
int min = 0;

typedef struct {
  int *numbers;
  int count;
} Data;

void *calculate_average(void *param) {
  Data *data = (Data *)param;
  int sum = 0;
  for (int i = 0; i < data->count; i++) {
    sum += data->numbers[i];
  }
  average = sum / (double)data->count;
  pthread_exit(0);
}

void *calculate_max(void *param) {
  Data *data = (Data *)param;
  for (int i = 0; i < data->count; i++) {
    if (max < data->numbers[i]) {
      max = data->numbers[i];
    }
  }
  pthread_exit(0);
}

void *calculate_min(void *param) {
  Data *data = (Data *)param;
  for (int i = 0; i < data->count; i++) {
    if (min > data->numbers[i]) {
      min = data->numbers[i];
    }
  }
  pthread_exit(0);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <list tof numbers>", argv[0]);
    exit(1);
  }
  int num_count = argc - 1;
  int numbers[num_count];
  for (int i = 0; i < num_count; i++) {
    numbers[i] = atoi(argv[i + 1]);
  }
  min = numbers[0];
  max = numbers[0];

  Data data = {numbers, num_count};
  pthread_t thread_max, thread_min, thread_avg;
  pthread_create(&thread_max, NULL, calculate_max, &data);
  pthread_create(&thread_min, NULL, calculate_min, &data);
  pthread_create(&thread_avg, NULL, calculate_average, &data);
  pthread_join(thread_max, NULL);
  pthread_join(thread_min, NULL);
  pthread_join(thread_avg, NULL);
  printf("Max: %d\n", max);
  printf("Min: %d\n", min);
  printf("Average: %lf\n", average);

  return 0;
}
