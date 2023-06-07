#include <stdio.h>

int factorial(int n);

int main() {
    printf("The program finds the factorial of your entered number n\n");

    int n;
    int success = 1;
    printf("Enter a positive number n:\n");

    do {
        if (!success) {
            printf("Enter a positive number!\n");
        }
        int success = scanf("%d", &n) && n > 0;
        while (getchar() != '\n')
            ;
    } while (!success);

    FILE *file = fopen("out.txt", "w");

    printf("%d! = %d\n", n, factorial(n));
    fprintf(file, "%d! = %d\n", n, factorial(n));

    fclose(file);
    return 0;
}

int factorial(int n) {
    if (n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}