#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

int main() {
    printf("The program that fills an array with random numbers from your chosen interval\n");
    int arr[SIZE];
    int a, b, c;
    printf("Enter three numbers a, b and c, where a - minimum value, b - maximum value, c - number of elements that you generate:\n");
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    printf("c = ");
    scanf("%d", &c);
    if (a > b) {
        printf("a should not be larger than b!");
        return 0;
    } else if (c > SIZE) {
        printf("c should not be larger than %d!", SIZE);
        return 0;
    }
    srand(time(NULL));
    int interval = b - a + 1;

    printf("Result:\n");

    for (int i = 0; i < c; i++) {
        arr[i] = rand() % interval + a;
        printf("%d ", arr[i]);
    }

    return 0;
}