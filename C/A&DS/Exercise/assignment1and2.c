#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int sum(int *arr, int size)
{
  int sum = 0;
  for(int j = 0; j<size;j++)
  {
    sum += *(arr+j);

  }
  return sum;
}
void bubblesort(int *arr, int size)
{
  for(int i = 0; i < size-1; i++)
  {
    for(int j = 0; j < size - i - 1; j++)
    {
      if(*(arr+i) > *(arr+j+1))
      {
        swap( (arr+i) , (arr+j+1));
      }
    }
  }
}

int sumsubarray(int *arr, int start, int end)
{
  int sum = 0;
  for(int i = start; i <= end;i++)
  { 
    sum += *(arr+i);
  }
  return sum;
}

int main(){
  int size;
  int *p;
  printf("Size of array: ");
  scanf("%d", &size);
  p = (int*)calloc(size, sizeof(int));
  for(int i = 0; i< size;i++)
  {
    printf("Enter the number %d: ", i);
    scanf("%d", p + i);
  }
  
  int start, end;
  int sumarray = sum(p, size);
  printf("Choose the start of subarray: ");
  scanf("%d", &start);
  printf("Choose the end of the sub array: ");
  scanf("%d", &end);
  int sumofsubarray = sumsubarray(p, start, end);
  printf("Sum of subarray is %d.", sumofsubarray);
  printf("\n");
  return 0;
}
