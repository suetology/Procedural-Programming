#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int max = (a > c && (a >= b || a == b)) * a +
              (b > a && (b >= c || b == c)) * b +
              (c > b && (c >= a || c == a)) * c +
              (a == b && a == c) * a;

    printf("%d", max);

    return 0;
}
