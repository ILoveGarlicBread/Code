#include <stdio.h>

int mostfrequence(int *a, int n) {
  int i, count = 0, candidate;
  for (i = 0; i < n; i++) {
    if (count == 0) {
      candidate = a[i];
      count = 1;
    } else if (a[i] == candidate) {
      count++;
    } else {
      count--;
    }
  }
  return candidate;
}

int main() {
  int arr[] = {2, 2, 1, 1, 2, 2};
  int result = mostfrequence(arr, 6);
  printf("%d\n", result);
}
