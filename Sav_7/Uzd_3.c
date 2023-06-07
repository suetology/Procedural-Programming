#include <stdio.h>

int getPositiveNumber(char *msg);

int main() {
    int n = getPositiveNumber("Enter a positive number:");
    printf("%d\n", n);

    return 0;
}

int getPositiveNumber(char *msg) {
    int n;
    int success = 1;
    do {
        printf("%s\n", msg);
        success = scanf("%d", &n) && n > 0;
        while (getchar() != '\n')
            ;
    } while (!success);
    return n;
}