#include <stdio.h>

int max(int a, int b, int c);

int FindGCD(int n1, int n2);

int main() {
    printf("The program finds the greatest common divisor and the least common multiple of you chosen natural numbers a, b and c\n");

    int a, b, c;
    printf("Enter number a:\n");
    scanf("%d", &a);
    printf("Enter number b:\n");
    scanf("%d", &b);
    printf("Enter number c:\n");
    scanf("%d", &c);
    
    int m = max(a, b, c);
    int lcm;
    for (lcm = m; lcm % a != 0 || lcm % b != 0 || lcm % c != 0; lcm += m)
        ;

    int gcd = FindGCD(a, FindGCD(b, c));

    printf("The greatest common divisor of those numbers is %d\n", gcd);
    printf("The least common multiple of those numbers is %d\n", lcm);
    return 0;
}

int FindGCD(int n1, int n2) {
    if (n2 == 0) {
        return n1;
    }
    return FindGCD(n2, n1 % n2);
}

int max(int a, int b, int c) {
    return a < b ? b < c ? c : b : a;
}