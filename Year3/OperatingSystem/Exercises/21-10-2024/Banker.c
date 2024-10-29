#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_OF_CUSTOMERS 5
#define NUMBER_OF_RESOURCES 4

int available[NUMBER_OF_RESOURCES]; 
int maximum[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES]; 
int allocation[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES]; 
int need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES]; 

void initialize(char *filename);
bool request_resources(int customer_num, int request[]);
void release_resources(int customer_num, int release[]);
bool is_safe();
void output_status();
void calculate_need();
void process_command(char *command);

int main(int argc, char *argv[]) {
    if (argc != NUMBER_OF_RESOURCES + 1) {
        printf("Usage: %s <resource1> <resource2> ... <resourceN>\n", argv[0]);
        exit(1);
    }

    for (int i = 0; i < NUMBER_OF_RESOURCES; i++) {
        available[i] = atoi(argv[i + 1]);
    }

    initialize("max_demand.txt");

    calculate_need();

    char command[100];
    while (true) {
        printf("Enter command (RQ/RL/*): ");
        fgets(command, sizeof(command), stdin);
        process_command(command);
    }

    return 0;
}

void initialize(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
        for (int j = 0; j < NUMBER_OF_RESOURCES; j++) {
            fscanf(file, "%d,", &maximum[i][j]);
        }
    }
    fclose(file);
}

void calculate_need() {
    for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
        for (int j = 0; j < NUMBER_OF_RESOURCES; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

void process_command(char *command) {
    if (command[0] == 'R' && command[1] == 'Q') {
        int customer_num, request[NUMBER_OF_RESOURCES];
        sscanf(command, "RQ %d %d %d %d %d", &customer_num, &request[0], &request[1], &request[2], &request[3]);

        if (request_resources(customer_num, request)) {
            printf("Request granted.\n");
        } else {
            printf("Request denied.\n");
        }
    } else if (command[0] == 'R' && command[1] == 'L') {
        int customer_num, release[NUMBER_OF_RESOURCES];
        sscanf(command, "RL %d %d %d %d %d", &customer_num, &release[0], &release[1], &release[2], &release[3]);

        release_resources(customer_num, release);
        printf("Resources released.\n");
    } else if (command[0] == '*') {
        output_status();
    } else {
        printf("Invalid command.\n");
    }
}

bool request_resources(int customer_num, int request[]) {
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++) {
        if (request[i] > need[customer_num][i]) {
            return false;
        }
    }

    for (int i = 0; i < NUMBER_OF_RESOURCES; i++) {
        if (request[i] > available[i]) {
            return false;
        }
    }

    for (int i = 0; i < NUMBER_OF_RESOURCES; i++) {
        available[i] -= request[i];
        allocation[customer_num][i] += request[i];
        need[customer_num][i] -= request[i];
    }

    if (is_safe()) {
        return true;
    } else {
        for (int i = 0; i < NUMBER_OF_RESOURCES; i++) {
            available[i] += request[i];
            allocation[customer_num][i] -= request[i];
            need[customer_num][i] += request[i];
        }
        return false;
    }
}

void release_resources(int customer_num, int release[]) {
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++) {
        allocation[customer_num][i] -= release[i];
        available[i] += release[i];
        need[customer_num][i] += release[i];
    }
}

bool is_safe() {
    int work[NUMBER_OF_RESOURCES];
    bool finish[NUMBER_OF_CUSTOMERS] = {false};

    for (int i = 0; i < NUMBER_OF_RESOURCES; i++) {
        work[i] = available[i];
    }

    while (true) {
        bool found = false;
        for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
            if (!finish[i]) {
                bool can_finish = true;
                for (int j = 0; j < NUMBER_OF_RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        can_finish = false;
                        break;
                    }
                }
                if (can_finish) {
                    for (int j = 0; j < NUMBER_OF_RESOURCES; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) break;
    }

    for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
        if (!finish[i]) {
            return false;
        }
    }
    return true;
}

void output_status() {
    printf("\nAvailable resources:\n");
    for (int i = 0; i < NUMBER_OF_RESOURCES; i++) {
        printf("%d ", available[i]);
    }
    printf("\n\nMaximum resources:\n");
    for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
        for (int j = 0; j < NUMBER_OF_RESOURCES; j++) {
            printf("%d ", maximum[i][j]);
        }
        printf("\n");
    }
    printf("\nAllocated resources:\n");
    for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
        for (int j = 0; j < NUMBER_OF_RESOURCES; j++) {
            printf("%d ", allocation[i][j]);
        }
        printf("\n");
    }
    printf("\nNeed resources:\n");
    for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
        for (int j = 0; j < NUMBER_OF_RESOURCES; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

