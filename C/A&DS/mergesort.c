#include <stdio.h>
void merge(int arr[], int left, int mid, int right) {
  int i, j, k;

  int left_size = mid - left + 1;
  int right_size = right - mid;
  int left_half[left_size];
  int right_half[right_size];
  for (i = 0; i < left_size; i++) {
    left_half[i] = arr[left + i];
  }
  for (j = 0; j < right_size; j++) {
    right_half[j] = arr[mid + 1 + j];
  }
  i = 0;
  j = 0;
  k = left;
  while (i < left_size && j < right_size) {
    if (left_half[i] <= right_half[j]) {
      arr[k] = left_half[i];
      i++;
    } else {
      arr[k] = right_half[j];
      j++;
    }
    k++;
  }
  while (j < right_size) {
    arr[k] = right_half[j];
    j++;
    k++;
  }
  while (i < left_size) {
    arr[k] = left_half[i];
    i++;
    k++;
  }
}
void merge_sort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

void print_array(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("[%d]", arr[i]);
  }
  printf("\n");
}
int main() {
  int arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Given array is \n");
  print_array(arr, n);
  merge_sort(arr, 0, n - 1);
  printf("\nSorted array is \n");
  print_array(arr, n);
  printf("\n");
  return 0;
}
