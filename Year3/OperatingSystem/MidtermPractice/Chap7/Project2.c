#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_CHAIRS 3
#define NUM_STUDENTS 10

// Shared variables
sem_t ta_sem;               // Semaphore to signal the TA
sem_t student_sem;          // Semaphore to signal students
pthread_mutex_t chair_mutex; // Mutex for accessing chairs

int waiting_students = 0;    // Count of waiting students

// Teaching Assistant (TA) thread function
void* ta_thread(void* arg) {
    while (1) {
        // Wait for a student to arrive and wake the TA
        sem_wait(&ta_sem);

        // TA helps a student
        pthread_mutex_lock(&chair_mutex);
        waiting_students--; // One student being helped
        printf("TA: Helping a student. Waiting students: %d\n", waiting_students);
        sem_post(&student_sem); // Signal student that TA is ready to help
        pthread_mutex_unlock(&chair_mutex);

        // Simulate time taken to help a student
        sleep(1);
        printf("TA: Finished helping a student.\n");

        // If no students are waiting, the TA can go back to sleep
    }
}

// Student thread function
void* student_thread(void* arg) {
    int student_id = *(int*)arg;
    free(arg);

    while (1) {
        sleep(rand() % 5); // Simulate arrival time of student

        pthread_mutex_lock(&chair_mutex);
        if (waiting_students < NUM_CHAIRS) {
            waiting_students++;
            printf("Student %d: Waiting. Waiting students: %d\n", student_id, waiting_students);
            sem_post(&ta_sem); // Wake up TA if sleeping
            pthread_mutex_unlock(&chair_mutex);

            // Wait for the TA to be available
            sem_wait(&student_sem);
            printf("Student %d: Receiving help from TA.\n", student_id);
        } else {
            // No chairs available, student leaves and returns later
            pthread_mutex_unlock(&chair_mutex);
            printf("Student %d: No chairs available, will come back later.\n", student_id);
        }
    }
}

int main() {
    pthread_t ta;
    pthread_t students[NUM_STUDENTS];

    // Initialize semaphores and mutex
    sem_init(&ta_sem, 0, 0);        // Initially TA is asleep
    sem_init(&student_sem, 0, 0);   // Semaphore for students waiting to be helped
    pthread_mutex_init(&chair_mutex, NULL);

    // Create TA thread
    pthread_create(&ta, NULL, ta_thread, NULL);

    // Create student threads
    for (int i = 0; i < NUM_STUDENTS; i++) {
        int* student_id = malloc(sizeof(int));
        *student_id = i + 1;
        pthread_create(&students[i], NULL, student_thread, student_id);
    }

    // Join student threads (in this example, they will run indefinitely)
    for (int i = 0; i < NUM_STUDENTS; i++) {
        pthread_join(students[i], NULL);
    }

    // Destroy semaphores and mutex (will never reach here in this infinite loop example)
    sem_destroy(&ta_sem);
    sem_destroy(&student_sem);
    pthread_mutex_destroy(&chair_mutex);

    return 0;
}

