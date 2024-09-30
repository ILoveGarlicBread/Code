#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 11

typedef struct {
    int row;
    int col;
} Parameters;

int sudoku[9][9] = {
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}
};

int result[NUM_THREADS] = {0};
// return 1 to result[] if a digit is valid, 0 if there is duplicate
void* check_rows(void* arg) {
    for (int i = 0; i < 9; i++) {
        int seen[10] = {0};
        for (int j = 0; j < 9; j++) {
            if (seen[sudoku[i][j]] == 1) {
                result[0] = 0;
                pthread_exit(NULL);
            }
            seen[sudoku[i][j]] = 1;
        }
    }
    result[0] = 1;
    pthread_exit(NULL);
}

void* check_columns(void* arg) {
    for (int i = 0; i < 9; i++) {
        int seen[10] = {0};
        for (int j = 0; j < 9; j++) {
            if (seen[sudoku[j][i]] == 1) {
                result[1] = 0;
                pthread_exit(NULL);
            }
            seen[sudoku[j][i]] = 1;
        }
    }
    result[1] = 1;
    pthread_exit(NULL);
}

void* check_subgrid(void* arg) {
    Parameters* params = (Parameters*) arg;
    int row = params->row;
    int col = params->col;

    int seen[10] = {0};
    for (int i = row; i < row + 3; i++) {
        for (int j = col; j < col + 3; j++) {
            if (seen[sudoku[i][j]] == 1) {
                result[row + col / 3 + 2] = 0; 
                pthread_exit(NULL);
            }
            seen[sudoku[i][j]] = 1;
        }
    }
    result[row + col / 3 + 2] = 1;
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    Parameters params[9];
    pthread_create(&threads[0], NULL, check_rows, NULL);
    pthread_create(&threads[1], NULL, check_columns, NULL);
    int thread_index = 2;
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            params[thread_index - 2].row = i;
            params[thread_index - 2].col = j;
            pthread_create(&threads[thread_index], NULL, check_subgrid, &params[thread_index - 2]);
            thread_index++;
        }
    }
    
    // Wait to finish threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Check results 
    for (int i = 0; i < NUM_THREADS; i++) {
        if (result[i] == 0) {
            printf("Sudoku solution is invalid. Boo! Try another one.\n");
            return 0;
        }
    }
    printf("Sudoku solution is valid.\n");
    return 0;
}

