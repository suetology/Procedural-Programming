#include <stdio.h>

int getFactorial(int number);
int getFactorialAgain(int number);

int main() {
    printf("%d\n", getFactorial(4));
    printf("%d\n", getFactorialAgain(4));
    printf("%d\n", getFactorial(5));
    printf("%d\n", getFactorialAgain(5));
    printf("%d\n", getFactorial(6));
    printf("%d\n", getFactorialAgain(6));
    printf("%d\n", getFactorial(7));
    printf("%d\n", getFactorialAgain(7));

    return 0;
}

int getFactorial(int number) {
    if (number <= 0) {
        return 0;
    }
    if (number == 1) {
        return 1;
    }
    return number * getFactorial(number - 1);
}

int getFactorialAgain(int number) {
    int factorial = 1;
    if (number <= 0) {
        return 0;
    }
    for (int i = 2; i <= number; i++) {
        factorial *= i;
    }
    return factorial;
}