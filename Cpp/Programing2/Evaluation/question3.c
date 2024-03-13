#include <stdio.h>
#include <stdlib.h>

void inputarray(int *array, int col, int row) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("Input element at [%d][%d]: ", i, j);
            scanf("%d", (array + i * row) + j);
        }
    }
}

void print_array(int *array, int col, int row) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d ", *((array + i * row) + j));
        }
        printf("\n");
    }
}

void sumrowodd_array(int *array, int *result, int col, int row) {
    for (int i = 0; i < col; i++) {
        int rowsum = 0;
        for (int j = 0; j < row; j++) {
            if (*((array + i * row) + j) % 2 != 0) {
                rowsum += *((array + i * row) + j);
            }
        }
        result[i] = rowsum;
    }
}

int sumSquaredDiagonal(int *array, int col, int row) {
    int sum = 0;
    for (int i = 0; i < col && i < row; i++) {
        int element = *((array + i * row) + i);
        sum += element * element;
    }
    return sum;
}

int main() {
    int row, col;
    int *array;
    printf("Number of rows for array: ");
    scanf("%d", &row);
    printf("Number of columns for array: ");
    scanf("%d", &col);
    array = (int *)calloc(row * col, sizeof(int));
    inputarray(array, col, row);
    printf("Array:\n");
    print_array(array, col, row);
    int result[row]; 
    sumrowodd_array(array, result, col, row);
    printf("Sum of odd elements in each row: ");
    for (int i = 0; i < col; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    int sumSquaredDiag = sumSquaredDiagonal(array, col, row);
    printf("Sum of squared diagonal elements: %d\n", sumSquaredDiag);
    printf("\n");
    free(array); 
    return 0;
}

