#include <stdio.h>

void swap(unsigned int *a, unsigned int *b);

int main() {
    int a = 5;
    int b = 6;
    swap(&a, &b);
    
    printf("%d%d", a, b);

    return 0;
}

void swap(unsigned int *a, unsigned int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}