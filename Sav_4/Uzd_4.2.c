#include <stdio.h>

int main() {
    printf("The program finds all positive numbers from the interval (a, b] that are divisible by a number c with a remainder of 1, where a, b, c are your chosen numbers\n");
    int a, b, c;
    printf("Enter number a:\n");
    scanf("%d", &a);
    printf("Enter number b:\n");
    scanf("%d", &b);
    
    if (a >= b) {
        printf("Number b should be larger than a!\n");
        return 0;
    }
    printf("Enter number c:\n");
    scanf("%d", &c);

    if (c <= 0) {
        printf("Number c should be positive!\n");
        return 0;
    }
    
    printf("The results are:\n");
    for (int i = a + 1; i <= b; i++) {
        if (i > 0 && i % c == 1) {
            printf("%d\n", i);
        }
    }
    return 0;
}