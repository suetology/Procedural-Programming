#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x, y, z;
    scanf("%lf %lf %lf", &x, &y, &z);

    double e1 = x + 4 * y + pow(z, 3);
    double e2 = (x + sqrt(y)) * (pow(z, 4) - abs(z) + 46.3);

    printf("%lf + 4 * %lf + %lf^3 = %lf \n", x, y, z, e1);
    printf("(%lf + %lf^(1/2)) * (%lf^4 - |%lf| + 46.3 = %lf", x, y, z, z, e2);

    return 0;
}
