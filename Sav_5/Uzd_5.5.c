#include <stdio.h>
#include <string.h>

int main() {
    printf("The program checks if it is possible to create numbers in array from the digits of number x\n");

    int x;
    printf("Enter number x:\n");
    scanf("%d", &x);

    int n;
    printf("Enter number of elements in the array:\n");
    scanf("%d", &n);

    int numbers[n];
    for (int i = 0; i < n; i++) {
        printf("Enter number #%d\n", i + 1);
        scanf("%d", &numbers[i]);
    }

    int xDigits[10] = { 0 };
    int temp = x;
    while (temp > 0) {
        xDigits[temp % 10]++;
        temp /= 10;
    }
    
    printf("Numbers that you can create from number %d digits:\n", x);
    for (int i = 0; i < n; i++) {
        int copy[10];
        memcpy(copy, xDigits, 10 * sizeof(int));
        int temp = numbers[i];
        while (temp > 0) {
            if (copy[temp % 10] > 0) {
                copy[temp % 10]--;
            } else {
                break;
            }
            temp /= 10;
        }
        if (temp == 0) {
            printf("%d\n", numbers[i]);
        }
    }

    return 0;
}