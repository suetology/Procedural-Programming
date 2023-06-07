#include <stdio.h>

int isInRange(int number, int low, int high);

int main() {
    printf("%d", isInRange(6, 4, 10));
    printf("%d", isInRange(4, 4, 10));
    printf("%d", isInRange(4, 4, 4));
    printf("%d", isInRange(10, 4, 10));
    printf("%d", isInRange(4, 10, 9));

    return 0;
}

int isInRange(int number, int low, int high) {
    return number >= low && number <= high && low <= high;
}