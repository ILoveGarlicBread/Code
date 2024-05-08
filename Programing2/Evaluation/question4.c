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

void sumroweven_array(int *array, int *result, int col, int row) {
    for (int i = 0; i < col; i++) {
        int rowsum = 0;
        for (int j = 0; j < row; j++) {
            if (j % 2 == 0) {
                rowsum += *((array + i * row) + j);
            }
        }
        result[i] = rowsum;
    }
}

int sumDoulbleSquaredDiagonal(int *array, int col, int row) {
    int sum = 0;
    for (int i = 0; i < col && i < row; i++) {
        int element = *((array + i * row) + i);
        sum +=2* element * element;
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
    sumroweven_array(array, result, col, row);
    printf("Sum of even elements in each row: ");
    for (int i = 0; i < col; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    int sumDoubleSquaredDiag = sumDoulbleSquaredDiagonal(array, col, row);
    printf("Sum of doubled squared diagonal elements: %d\n", sumDoubleSquaredDiag);
    printf("\n");
    free(array); 
    return 0;
}

