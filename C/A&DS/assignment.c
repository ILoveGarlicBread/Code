#include <stdio.h>
int find_most_frequent(int arr[], int n)
{
  int max_count = 0;
  int max_element;
  for (int i = 0; i < n; i++)
  {
    int count = 1;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] == arr[j])
        count++;
    }
    if (count > max_count)
    {
      max_count = count;
      max_element = arr[i];
    }
  }
  return max_element;
}
int main(){
  int arr[] = {1,2,4,18,2,10,3,18,2};
  int arr2[] = {1,5,3,8,9,6,5,9,0,1,1,6,5,5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  int result=find_most_frequent(arr, n);
  int result2=find_most_frequent(arr2, n2);
  printf("Most frequent element in array 1 is %d\n", result);
  printf("Most frequent element in array 2 is %d\n", result2);
  printf("\n");
  return 0;
}
