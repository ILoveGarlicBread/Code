#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_PAGES 10
#define MAX_REFERENCES 20

typedef struct {
  int *references;
  int num_pages;
  int num_frames;
  int page_faults;
} ThreadData;

void *fifo(void *arg) {
  ThreadData *data = (ThreadData *)arg;
  int frame[data->num_frames];
  int index = 0;
  data->page_faults = 0;

  for (int i = 0; i < data->num_frames; i++) {
    frame[i] = -1;
  }

  for (int i = 0; i < data->num_pages; i++) {
    int is_page_present = 0;
    for (int j = 0; j < data->num_frames; j++) {
      if (frame[j] == data->references[i]) {
        is_page_present = 1;
        break;
      }
    }
    if (!is_page_present) {
      frame[index] = data->references[i];
      index = (index + 1) % data->num_frames;
      data->page_faults++;
    }
  }

  return NULL;
}

void *lru(void *arg) {
  ThreadData *data = (ThreadData *)arg;
  int frame[data->num_frames];
  int last_used[data->num_frames];
  data->page_faults = 0;

  for (int i = 0; i < data->num_frames; i++) {
    frame[i] = -1;
    last_used[i] = -1;
  }

  for (int i = 0; i < data->num_pages; i++) {
    int is_page_present = 0;
    for (int j = 0; j < data->num_frames; j++) {
      if (frame[j] == data->references[i]) {
        is_page_present = 1;
        last_used[j] = i;
        break;
      }
    }
    if (!is_page_present) {
      int lru_index = 0;
      for (int j = 1; j < data->num_frames; j++) {
        if (last_used[j] < last_used[lru_index]) {
          lru_index = j;
        }
      }
      frame[lru_index] = data->references[i];
      last_used[lru_index] = i;
      data->page_faults++;
    }
  }

  return NULL;
}

void *optimal(void *arg) {
  ThreadData *data = (ThreadData *)arg;
  int frame[data->num_frames];
  data->page_faults = 0;

  for (int i = 0; i < data->num_frames; i++) {
    frame[i] = -1;
  }

  for (int i = 0; i < data->num_pages; i++) {
    int is_page_present = 0;
    for (int j = 0; j < data->num_frames; j++) {
      if (frame[j] == data->references[i]) {
        is_page_present = 1;
        break;
      }
    }

    if (!is_page_present) {
      int empty_index = -1;
      for (int j = 0; j < data->num_frames; j++) {
        if (frame[j] == -1) {
          empty_index = j;
          break;
        }
      }
      if (empty_index != -1) {
        frame[empty_index] = data->references[i];
        data->page_faults++;
      } else {
        int farthest_index = 0;
        int farthest_distance = -1;
        for (int j = 0; j < data->num_frames; j++) {
          int next_use = -1;
          for (int k = i + 1; k < data->num_pages; k++) {
            if (frame[j] == data->references[k]) {
              next_use = k;
              break;
            }
          }
          if (next_use == -1) {
            farthest_index = j;
            break;
          } else if (next_use > farthest_distance) {
            farthest_distance = next_use;
            farthest_index = j;
          }
        }
        frame[farthest_index] = data->references[i];
        data->page_faults++;
      }
    }
  }

  return NULL;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <number_of_frames> <page_reference_string>\n", argv[0]);
    return 1;
  }

  int num_frames = atoi(argv[1]);
  if (num_frames <= 0 || num_frames > MAX_PAGES) {
    printf("Number of frames must be between 1 and %d.\n", MAX_PAGES);
    return 1;
  }

  int references[MAX_REFERENCES];
  int num_pages = argc - 2;

  for (int i = 0; i < num_pages; i++) {
    references[i] = atoi(argv[i + 2]);
  }

  pthread_t fifo_thread, lru_thread, optimal_thread;
  ThreadData fifo_data = {references, num_pages, num_frames, 0};
  ThreadData lru_data = {references, num_pages, num_frames, 0};
  ThreadData optimal_data = {references, num_pages, num_frames, 0};

  pthread_create(&fifo_thread, NULL, fifo, &fifo_data);
  pthread_create(&lru_thread, NULL, lru, &lru_data);
  pthread_create(&optimal_thread, NULL, optimal, &optimal_data);

  pthread_join(fifo_thread, NULL);
  pthread_join(lru_thread, NULL);
  pthread_join(optimal_thread, NULL);

  printf("Page faults: \n");
  printf("FIFO: %d\n", fifo_data.page_faults);
  printf("LRU: %d\n", lru_data.page_faults);
  printf("Optimal: %d\n", optimal_data.page_faults);

  return 0;
}

