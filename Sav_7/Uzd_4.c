#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CAPACITY 10

void generateArray(int data[], int size, int low, int high);

int main() {
    srand(time(NULL));
    int arr[CAPACITY];
    generateArray(arr, CAPACITY, 1, 10);

    for (int i = 0; i < CAPACITY; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}

void generateArray(int data[], int size, int low, int high) {
    for (int i = 0; i < size; i++) {
        data[i] = rand() % (high - low + 1) + low;
    }
}