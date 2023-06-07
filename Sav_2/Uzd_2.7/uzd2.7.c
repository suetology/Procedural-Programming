#include <stdio.h>
#include <stdlib.h>

int Pow(int number, int power);

int main() {
    int n;
    scanf("%d", &n);

    int k = n, size = 0;
    while (k > 0) {
        k /= 10;
        size++;
    }

    for (int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - 1; j++) {

            if (n / Pow(10, j) % 10 > n / Pow(10, j + 1) % 10) {
                n = n / Pow(10, j + 2) * Pow(10, j + 2) + n % Pow(10, j) + (n / Pow(10, j) % 10 ) * Pow(10, j + 1) + (n / Pow(10, j + 1) % 10) * Pow(10, j);
            }
        }
    }
    printf("%d \n", n);

    return 0;
}

int Pow(int number, int power) {
    int result = 1;
    while(power > 0) {
        result *= number;
        power--;
    }
    return result;
}
