#include <stdio.h>

#define SIZE 10

void printArray(int *arr, int size);
void eraseElement(int *arr, int size, int place);
void addElement(int *arr, int size, int place, int value);

int main() {
    //a
    int arr[SIZE] = { 0 };
    //b
    printArray(arr, SIZE);
    //c
    arr[0] = 1;
    arr[3] = 2;
    arr[9] = 3;
    //d
    eraseElement(arr, SIZE, 2);
    //e
    addElement(arr, SIZE, 6, 4);
    //f
    printArray(arr, SIZE);
    //g
    printf("Enter an index of an element that you want to change and then specify a new value:\n");
    int x, y;
    scanf("%d %d", &x, &y);
    if(x < 0 || x >= SIZE) {
        printf("You have entered an index that goes out of the array bounds!\n");
        return 0;
    }
    arr[x] = y;
    //h
    printf("Enter an index of an element that you want to erase:\n");
    scanf("%d", &x);
    if(x < 0 || x >= SIZE) {
        printf("You have entered an index that goes out of the array bounds!\n");
        return 0;
    }
    eraseElement(arr, SIZE, x);
    //i
    printf("Enter an index of a place where you want to add an element and then specify a new value:\n");
    scanf("%d %d", &x, &y);
    if(x < 0 || x >= SIZE) {
        printf("You have entered an index that goes out of the array bounds!\n");
        return 0;
    }
    addElement(arr, SIZE, x, y);
    //j
    printArray(arr, SIZE);

    return 0;
}

void printArray(int *arr, int size) {
    printf("Current state of array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void eraseElement(int *arr, int size, int place) {
    for (int i = place; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = 0;
}

void addElement(int *arr, int size, int place, int value) {
    for (int i = size - 1; i > place; i--) {
        arr[i] = arr[i - 1];
    }
    arr[place] = value; 
}