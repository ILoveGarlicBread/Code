#include <stdio.h>
#include <stdlib.h>

#define MIN_PID 300
#define MAX_PID 5000
#define PID_RANGE (MAX_PID - MIN_PID + 1)

int *pid_map = NULL;  // Bitmap to manage PIDs

// Function to initialize the PID manager
int allocate_map(void) {
    pid_map = (int *)malloc(PID_RANGE * sizeof(int));
    if (pid_map == NULL) {
        return -1;  // Memory allocation failed
    }

    // Initialize all PIDs to available (0 means available)
    for (int i = 0; i < PID_RANGE; i++) {
        pid_map[i] = 0;
    }
    return 1;  // Success
}

// Function to allocate and return a PID
int allocate_pid(void) {
    if (pid_map == NULL) {
        return -1;  // PID map not initialized
    }

    // Find an available PID in the range
    for (int i = 0; i < PID_RANGE; i++) {
        if (pid_map[i] == 0) {       // 0 means PID is available
            pid_map[i] = 1;          // Mark as in use
            return i + MIN_PID;      // Return the actual PID
        }
    }
    return -1;  // No PIDs available
}

// Function to release a PID
void release_pid(int pid) {
    if (pid < MIN_PID || pid > MAX_PID || pid_map == NULL) {
        return;  // PID out of range or map not initialized
    }
    pid_map[pid - MIN_PID] = 0;  // Mark PID as available
}

// Main function to test the PID manager
int main() {
    if (allocate_map() == -1) {
        fprintf(stderr, "Failed to initialize PID manager.\n");
        return 1;
    }

    int pid1 = allocate_pid();
    printf("Allocated PID: %d\n", pid1);

    int pid2 = allocate_pid();
    printf("Allocated PID: %d\n", pid2);

    release_pid(pid1);
    printf("Released PID: %d\n", pid1);

    int pid3 = allocate_pid();
    printf("Allocated PID: %d\n", pid3);

    // Clean up
    free(pid_map);
    return 0;
}

