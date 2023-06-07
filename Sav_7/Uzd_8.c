#include <stdio.h>

void quickSortIter(int arr[], int low, int high);
void quickSortRec(int arr[], int low, int high);
int medianOfThreePivot(int arr[], int low, int high);
void swap(int *n1, int *n2);
void insetionSort(int arr[], int low, int high);

int main() {
    int arr[] = { 5, 1, 0, 8, 2, 9, 1, 11, 6, 3, 10, 1, 0, 5, 4, 7, 12, 3 };
    quickSortIter(arr, 0, 17);
    for (int i = 0; i < 18; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

int medianOfThreePivot(int arr[], int low, int high) {
    int middle = (low + high) / 2;

    if (arr[low] > arr[middle]) {
        swap(&arr[low], &arr[middle]);
    }
    if (arr[low] > arr[high]) {
        swap(&arr[low], &arr[high]);
    }
    if (arr[middle] > arr[high]) {
        swap(&arr[middle], &arr[high]);
    }

    swap(&arr[middle], &arr[high - 1]);

    int pivot = arr[high - 1];

    int j = low;
    for (int i = low + 1; i <= high - 2; i++) {
        if (arr[i] < pivot) {
            j++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[j + 1], &arr[high - 1]);
    return j + 1;   
}

void quickSortIter(int arr[], int low, int high) {
    if (low > high) {
        return; 
    }
    int cutoff = 5;
    int stack[high - low + 1];
    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        if (low + cutoff > high) {
            insetionSort(arr, low, high);
            continue;
        } 

        int pivot = medianOfThreePivot(arr, low, high);

        if (pivot - 1 > low) {
            stack[++top] = low;
            stack[++top] = pivot - 1;
        }

        if (pivot + 1 < high) {
            stack[++top] = pivot + 1;
            stack[++top] = high;
        }
    }
}

void quickSortRec(int arr[], int low, int high) {
    int cutoff = 5;
    if (low + cutoff > high) {
        insetionSort(arr, low, high);
    }
    else if (low < high) {
        int pivot = medianOfThreePivot(arr, low, high);
        quickSortRec(arr, low, pivot - 1);
        quickSortRec(arr, pivot + 1, high);
    }
}

void swap(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void insetionSort(int arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int temp = arr[i];
        int j;

        for (j = i; j > low && arr[j - 1] > temp; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}