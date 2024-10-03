#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 10

int array[SIZE];
int sorted_array[SIZE];

typedef struct {
    int start;
    int end;
} SortParams;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int start, int end) {
    if (start < end) {
        int pivot = array[end];
        int i = start - 1;
        for (int j = start; j < end; j++) {
            if (array[j] <= pivot) {
                i++;
                swap(&array[i], &array[j]);
            }
        }
        swap(&array[i + 1], &array[end]);
        int pi = i + 1;

        quick_sort(start, pi - 1);
        quick_sort(pi + 1, end);
    }
}

void* sort_thread(void* params) {
    SortParams* p = (SortParams*) params;
    quick_sort(p->start, p->end);
    pthread_exit(0);
}

void* merge_thread(void* args) {
    int mid = SIZE / 2;
    int i = 0, j = mid, k = 0;

    while (i < mid && j < SIZE) {
        if (array[i] <= array[j]) {
            sorted_array[k++] = array[i++];
        } else {
            sorted_array[k++] = array[j++];
        }
    }

    while (i < mid) {
        sorted_array[k++] = array[i++];
    }

    while (j < SIZE) {
        sorted_array[k++] = array[j++];
    }

    pthread_exit(0);
}

int main() {
    pthread_t tid1, tid2, tid3;
    SortParams params1, params2;

    printf("Unsorted array: ");
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }
    printf("\n");

    params1.start = 0;
    params1.end = SIZE / 2 - 1;
    params2.start = SIZE / 2;
    params2.end = SIZE - 1;

    pthread_create(&tid1, NULL, sort_thread, &params1);
    pthread_create(&tid2, NULL, sort_thread, &params2);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_create(&tid3, NULL, merge_thread, NULL);
    pthread_join(tid3, NULL);
    printf("Sorted array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", sorted_array[i]);
    }
    printf("\n");

    return 0;
}

