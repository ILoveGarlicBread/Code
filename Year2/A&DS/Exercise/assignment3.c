#include <stdio.h>
#include <stdlib.h>
void inputarray(int *array, int col, int row) {

  for (int i = 0; i < col; i++) {
    for (int j = 0; j < row; j++) {
      printf("Input element at [%d][%d]: ", i, j);
      scanf("%d", (array + i * col) + j);
    }
  }
}
void print_array(int *array, int col, int row) {
  for (int i = 0; i < col; i++) {
    for (int j = 0; j < row; j++) {
      printf("%d ", *((array + i * col) + j));
    }
    printf("\n");
  }
}

int sum_array(int *array, int col, int row) {
  int sum = 0;
  for (int i = 0; i < col; i++) {
    for (int j = 0; j < row; j++) {
      sum += *((array + i * col) + j);
    }
  }
  return sum;
}

void print_transpose(int *array, int col, int row) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("%d ", *((array + j * col) + i));
    }
    printf("\n");
  }
}

int main() {
  int row, col;
  int *array;
  int size = row * col;
  printf("Number of rows for array: ");
  scanf("%d", &row);
  printf("Number of columns for array: ");
  scanf("%d", &col);
  array = (int *)calloc(row * col, sizeof(int));
  inputarray(array, col, row);
  print_array(array, col, row);
  int sum = sum_array(array, col, row);
  printf("Sum of array is %d \n", sum);
  print_transpose(array, col, row);
  printf("\n");
  return 0;
}
