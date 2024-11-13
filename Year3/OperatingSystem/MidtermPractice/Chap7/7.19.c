#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 5
typedef struct {
  int count;             // Number of threads that have reached the barrier
  int threshold;         // Total number of threads required at the barrier
  pthread_mutex_t mutex; // Mutex for critical section
  pthread_cond_t cond;   // Condition variable for synchronization
} barrier_t;

barrier_t barrier;

/* Initializes the barrier to the specified number of threads */
int init(int n) {
  barrier.threshold = n;
  barrier.count = 0;
  if (pthread_mutex_init(&barrier.mutex, NULL) != 0) {
    return -1; // Error initializing mutex
  }
  if (pthread_cond_init(&barrier.cond, NULL) != 0) {
    return -1; // Error initializing condition variable
  }
  return 0;
}

/* Barrier point where threads will wait until all have reached */
int barrier_point(void) {
  if (pthread_mutex_lock(&barrier.mutex) != 0) {
    return -1; // Error locking mutex
  }

  barrier.count++;
  if (barrier.count == barrier.threshold) {
    // Last thread to reach the barrier releases all threads
    barrier.count = 0; // Reset for reuse
    if (pthread_cond_broadcast(&barrier.cond) != 0) {
      pthread_mutex_unlock(&barrier.mutex);
      return -1; // Error broadcasting condition variable
    }
  } else {
    printf("Reached barrier, waiting...\n");
    // Wait for the last thread to reach the barrier
    if (pthread_cond_wait(&barrier.cond, &barrier.mutex) != 0) {
      pthread_mutex_unlock(&barrier.mutex);
      return -1; // Error waiting on condition variable
    }
  }

  if (pthread_mutex_unlock(&barrier.mutex) != 0) {
    return -1; // Error unlocking mutex
  }
  return 0;
}

/* Clean up the barrier resources */
void barrier_destroy() {
  pthread_mutex_destroy(&barrier.mutex);
  pthread_cond_destroy(&barrier.cond);
}

void *thread_work(void *arg) {
  int thread_id = *((int *)arg);
  free(arg);

  printf("Thread %d: Starting work before barrier.\n", thread_id);
  sleep(1); // Simulate work

  printf("Thread %d: Reaching barrier.\n", thread_id);
  if (barrier_point() != 0) {
    fprintf(stderr, "Error at barrier point in thread %d\n", thread_id);
    pthread_exit(NULL);
  }

  printf("Thread %d: Passed the barrier, resuming work.\n", thread_id);
  sleep(1); // Simulate more work

  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];

  // Initialize the barrier for NUM_THREADS
  if (init(NUM_THREADS) != 0) {
    fprintf(stderr, "Error initializing barrier\n");
    return -1;
  }

  // Create threads
  for (int i = 0; i < NUM_THREADS; i++) {
    int *thread_id = malloc(sizeof(int));
    *thread_id = i;
    if (pthread_create(&threads[i], NULL, thread_work, thread_id) != 0) {
      fprintf(stderr, "Error creating thread %d\n", i);
      return -1;
    }
  }

  // Wait for all threads to complete
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Destroy barrier resources
  barrier_destroy();
  printf("All threads have completed.\n");

  return 0;
}
