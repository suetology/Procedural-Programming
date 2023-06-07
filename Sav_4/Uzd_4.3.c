#include <stdio.h>

int main() {
    printf("The program finds c-th number Fc, where Fc = Fc-1 + Fc-2 and F0 = a, F1 = b\n(a, b, c are your chosen non-negative numbers\n");

    int a, b, c;
    printf("Enter number a:\n");
    scanf("%d", &a);
    printf("Enter number b:\n");
    scanf("%d", &b);
    printf("Enter number c:\n");
    scanf("%d", &c);

    if (c == 0) {
        printf("The number #%d is equal to %d", c, a);
        return 0;
    } else if (c == 1) {
        printf("The number #%d is equal to %d", c, b);
        return 0;
    }
    int f0 = a, f1 = b, f2 = a + b;
    for (int i = 3; i <= c; i++) {
        f0 = f1;
        f1 = f2;
        f2 = f0 + f1;
    }
    printf("The number #%d is equal to %d", c, f2);
    return 0;
}