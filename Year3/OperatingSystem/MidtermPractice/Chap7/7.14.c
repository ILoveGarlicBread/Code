#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define MIN_PID 300
#define MAX_PID 5000
#define PID_RANGE (MAX_PID - MIN_PID + 1)
#define NUM_THREADS 100

// Array to keep track of allocated PIDs
int pid_map[PID_RANGE];

// Mutex lock to synchronize PID allocation and release
pthread_mutex_t pid_mutex;

// Function to initialize the PID manager
int allocate_map() {
    for (int i = 0; i < PID_RANGE; i++) {
        pid_map[i] = 0; // Mark all PIDs as available (0 means available)
    }
    return 0; // Successful initialization
}

// Function to allocate a PID
int allocate_pid() {
    pthread_mutex_lock(&pid_mutex); // Lock to ensure thread-safe access
    for (int i = 0; i < PID_RANGE; i++) {
        if (pid_map[i] == 0) { // PID is available
            pid_map[i] = 1;    // Mark as allocated
            pthread_mutex_unlock(&pid_mutex);
            return MIN_PID + i; // Return the allocated PID
        }
    }
    pthread_mutex_unlock(&pid_mutex);
    return -1; // No PID available
}

// Function to release a PID
void release_pid(int pid) {
    pthread_mutex_lock(&pid_mutex); // Lock to ensure thread-safe access
    pid_map[pid - MIN_PID] = 0;     // Mark as available
    pthread_mutex_unlock(&pid_mutex);
}

// Thread function for requesting, using, and releasing a PID
void *pid_user(void *param) {
    int pid = allocate_pid(); // Request a PID

    if (pid == -1) {
        printf("No available PID for thread %lu\n", pthread_self());
        pthread_exit(0);
    }

    printf("Thread %lu allocated PID %d\n", pthread_self(), pid);

    int sleep_time = rand() % 5 + 1; // Random sleep between 1 to 5 seconds
    sleep(sleep_time); // Simulate process execution time

    printf("Thread %lu releasing PID %d after %d seconds\n", pthread_self(), pid, sleep_time);
    release_pid(pid); // Release the PID

    pthread_exit(0);
}

int main() {
    srand(time(NULL)); // Seed random number generator
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&pid_mutex, NULL); // Initialize mutex

    // Initialize PID manager
    if (allocate_map() == -1) {
        fprintf(stderr, "Failed to initialize PID manager.\n");
        return -1;
    }

    // Create threads to simulate processes
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, pid_user, NULL);
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Clean up
    pthread_mutex_destroy(&pid_mutex);

    printf("All threads completed.\n");
    return 0;
}

