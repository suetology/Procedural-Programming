#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 11

int splitData(int data[], int initSize, int firstPartSize, int **arr1, int **arr2);

int main() {
    int f = 5;
    int arr[CAPACITY] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    int *arr1 = NULL;
    int *arr2 = NULL;
    if (splitData(arr, CAPACITY, f, &arr1, &arr2) == -1) {
        return -1;
    }

    for (int i = 0; i < f; ++i) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    for (int i = 0; i < CAPACITY - f; ++i) {
        printf("%d ", arr2[i]);
    }

    free(arr1);
    free(arr2);
    return 0;
}

int splitData(int data[], int initSize, int firstPartSize, int **arr1, int **arr2) {
    if (!data || *arr1 || *arr2) {
        return -1;
    }
    if (firstPartSize > initSize || initSize <= 0 || firstPartSize < 0) {
        return -1;
    }
    *arr1 = malloc(sizeof(int) * firstPartSize);
    *arr2 = malloc(sizeof(int) * (initSize - firstPartSize));

    for (int i = 0; i < firstPartSize; ++i) {
        (*arr1)[i] = data[i];
    }
    for (int i = 0; i < initSize - firstPartSize; ++i) {
        (*arr2)[i] = data[firstPartSize + i];
    }
    return 0;
}