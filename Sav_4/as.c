#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    double n = -1;
    char str[20];
    scanf("%s", str);
    n = strtod(str, NULL);
    printf("%lf\n", n);
    if (n != floor(n)) {
        printf("2345\n");
    }    
    return 0;
}