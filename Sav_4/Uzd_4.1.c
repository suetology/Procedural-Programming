#include <stdio.h>
#include <math.h>

int main() {
    printf("The program solves quadratic equasions with you chosen coefficients\n");
    int a, b, c;
    printf("Enter coefficient a:\n");
    scanf("%d", &a);
    printf("Enter coefficient b:\n");
    scanf("%d", &b);
    printf("Enter coefficient c:\n");
    scanf("%d", &c);

    int D = b * b - 4 * a * c;

    if (D < 0) {
        printf("There are no solutions :(");
    } else if (D == 0) {
        int x = (-(float)b) / (2.0f * a);
        printf("There is one solution:\nx = %d", x);
    } else {
        int x1 = (-(float)b + sqrt(D)) / (2.0f * a);
        int x2 = (-(float)b - sqrt(D)) / (2.0f * a);
        printf("There are two solutions:\nx1 = %d, x2 = %d", x1, x2);
    }

    return 0;
}