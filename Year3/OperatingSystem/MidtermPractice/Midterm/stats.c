#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float median = 0.0;
float standardDeviation = 0;

typedef struct {
  float *numbers;
  int count;
} Data;

void *find_median(void *param) {
  Data *data = (Data *)param;

  for (int i = 0; i < data->count; i++) {
    for (int j = 0; j < data->count - i - 1; j++) {
      if (data->numbers[j] > data->numbers[j + 1]) {
        int temp = data->numbers[j];
        data->numbers[j] = data->numbers[j + 1];
        data->numbers[j + 1] = temp;
      }
    }
  }
  if (data->count % 2 == 0) {
    median =
        (data->numbers[data->count / 2] + data->numbers[data->count / 2 + 1]) /
        2;
  } else {
    median = data->numbers[data->count / 2 + 1];
  }
  pthread_exit(0);
}
void *calculateStandardDeviation(void *param) {

  Data *data = (Data *)param;
  float sum = 0;
  for (int i = 0; i < data->count; i++) {
    sum += data->numbers[i];
  }
  float mean = sum / data->count;
  float values = 0;
  for (int i = 0; i < data->count; i++) {
    values += pow(data->numbers[i] - mean, 2);
  }

  float variance = values / (data->count-1);
  standardDeviation = sqrt(variance);
  pthread_exit(0);
}
int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <list tof numbers>", argv[0]);
    exit(1);
  }
  int num_count = argc - 1;
  float numbers[num_count];
  for (int i = 0; i < num_count; i++) {
    numbers[i] = atoi(argv[i + 1]);
  }
  Data data = {numbers, num_count};
  pthread_t median_thread, stddev_thread;
  pthread_create(&median_thread, NULL, find_median, &data);
  pthread_create(&stddev_thread, NULL, calculateStandardDeviation, &data);
  pthread_join(median_thread, NULL);
  pthread_join(stddev_thread, NULL);
  printf("Median: %.2f\n", median);
  printf("Standard Deviation: %.2f\n", standardDeviation);
  return 0;
}
