#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool char
#define true 1
#define false 0

int *subsetSum(int *arr, int size, int target);

int main() {
    printf("The program finds (if it exists) an array subset whose elements add up to a number x, where x and the array elements are your entered numbers\n");
    printf("Enter size of the array:\n");
    int size;
    scanf("%d", &size);
    int set[size];
    for (int i = 0; i < size; i++) {
        printf("Enter element #%d: ", i + 1);
        scanf("%d", &set[i]);
    }

    printf("Enter number x:\n");
    int x;
    scanf("%d", &x);

    int *subset = subsetSum(set, size, x);

    if (subset) {
        printf("The numbers that add up to %d:\n", x);
        for (int i = 0; i < 5 && subset[i] != 0; i++) {
            printf("%d ", subset[i]);
        }
    } else {
        printf("The subset whose elements add up to %d does not exist :(\n", x);
    }
    return 0;
}

int *subsetSum(int *arr, int size, int target) {
    bool flags[size + 1][target + 1];

    for (int i = 0; i <= size; i++) {
        flags[i][0] = true;
    }

    for (int i = 1; i <= target; i++) {
        flags[0][i] = false;
    }

    for (int y = 1; y <= size; y++) {
        for (int x = 1; x <= target; x++) {
            if (x < arr[y - 1]) {
                flags[y][x] = flags[y - 1][x];
            } else {
                flags[y][x] = flags[y - 1][x] | flags[y - 1][x - arr[y - 1]];
            }
        }
    }

    bool exists = false;
    for (int i = 1; i <= size; i++) {
        if (flags[i][target]) {
            exists = true;
            break;
        }
    }

    if (!exists) {
        return NULL;
    }

    int *subset = malloc(size * sizeof(*subset));
    memset(subset, 0, size * sizeof(int));
    int j = 0;

    while (target != 0) {  
        for (int i = 1; i <= size; i++) {
            if (flags[i][target]) {
                subset[j] = arr[i - 1];
                j++; 
                target -= arr[i - 1];
                break;
            }
        }
    }
    return subset;
}