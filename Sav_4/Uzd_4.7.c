#include <stdio.h>

void printBoundsSC();
void printBoundsUC();
void printBoundsSS();
void printBoundsUS();
void printBoundsSI();
void printBoundsUI();
void printBoundsSL();
void printBoundsUL();

int main() {
    printBoundsSC();
    printBoundsUC();
    printBoundsSS();
    printBoundsUS();
    printBoundsSI();
    printBoundsUI();
    printBoundsSL();
    printBoundsUL();
    

    return 0;
}

void printBoundsSC() {
    char n = 1;
    while (n > 0) {
        ++n;
    }
    printf("Bounds of signed char: [%d; %d]\n", n, (char)(n - 1));
}

void printBoundsUC() {
    unsigned char n = 1;
    while (n > 0) {
        ++n;
    }
    printf("Bounds of unsigned char: [%d; %d]\n", n, (unsigned char)(n - 1));
}

void printBoundsSS() {
    short n = 1;
    while (n > 0) {
        ++n;
    }
    printf("Bounds of signed short: [%hd; %hd]\n", n, (short)(n - 1));
}

void printBoundsUS() {
    unsigned short n = 1;
    while (n > 0) {
        ++n;
    }
    printf("Bounds of unsigned short: [%hu; %hu]\n", n, (unsigned short)(n - 1));
}

void printBoundsSI() {
    int n = 1;
    while (n > 0) {
        ++n;
    }
    printf("Bounds of signed int: [%d; %d]\n", n, (int)(n - 1));
}
void printBoundsUI() {
    unsigned int n = 1;
    while (n > 0) {
        ++n;
    }
    printf("Bounds of unsigned int: [%u; %u]\n", n, (unsigned int)(n - 1));
}

void printBoundsSL() {
    long n = 1;
    while (n > 0) {
        ++n;
    }
    printf("Bounds of signed long: [%ld; %ld]\n", n, (long)(n - 1));
}

void printBoundsUL() {
    unsigned long n = 1;
    while (n > 0) {
        ++n;
    }
    printf("Bounds of unsigned long: [%lu; %lu]\n", n, (unsigned long)(n - 1));
}