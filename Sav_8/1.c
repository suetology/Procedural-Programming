#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* createArray(int size, int low, int high);

int main() {
    srand(time(NULL));
    int *arr = createArray(10, 5, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", *(arr + i));
    }
    free(arr);
    return 0;
}

int* createArray(int size, int low, int high) {
    if (low > high) {
        return NULL;
    }
    int *array = malloc(size * sizeof(int));
    if (!array) {
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        *(array + i) = rand() % (high - low + 1) + low;
    }
    return array;
}