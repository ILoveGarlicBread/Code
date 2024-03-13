#include <stdio.h>
#include <stdlib.h>
// 2.1
void minmaxarray(int *array, int size, int min, int max)
{
  for (int i = 0; i < size; i++) {
        if (array[i] < min) {
            array[i] = min;
        } else if (array[i] > max) {
            array[i] = max;
        }
    }
}

void printarray(int *array, int size)
{
  for (int i = 0; i< size; i++)
  {
    printf("%d ", *(array+i));
  }
}
// 2.2
void calculateDifference(int input[], int diff[], int sign[], int size) {
    if (size <= 1) {
        return; 
    }
    int *diffPtr = diff;
    int *signPtr = sign;
    for (int i = 1; i < size; i++) {
        *diffPtr = input[i] - input[i - 1];
        *signPtr = (*diffPtr < 0) ? -1 : 1;
        diffPtr++;
        signPtr++;
    }
}
int main()
{
  int input[] = {1, 3, 7, 1, 2, 6, 0, 1};
  int size = sizeof(input) / sizeof(input[0]);
  int diff[size - 1]; 
  int sign[size - 1];
  calculateDifference(input, diff, sign, size);
  printf("Input Array:\t");
  for (int i = 0; i < size; i++) {
      printf("%d ", input[i]);
  }
  printf("\n");
  printf("Diff Array:\t");
  for (int i = 0; i < size - 1; i++) {
      printf("%d ", diff[i]);
  }
  printf("\n");
  printf("Sign Array:\t");
  for (int i = 0; i < size - 1; i++) {
      printf("%d ", sign[i]);
  }

/*
  int size = 10;                                                                                                     
  int *array = (int *)malloc(size * sizeof(int));                                                                 
  for(int i = 0; i< 10; i++)
  {
    *(array+i)=i;
  }
  printf("Original array: \n");
  printarray(array, size);
  int min = 3;
  int max = 7;
  printf("\n");
  minmaxarray(array, size, min, max);
  printarray(array, size);
  printf("\n");
  return 0;
*/


}
