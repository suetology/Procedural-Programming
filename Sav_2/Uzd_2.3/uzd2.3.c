#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    char* result;

    n % 2 == 0 ? (result = "Skaicius lyginis") : (result = "Skaicius nelyginis");

    printf("%s", result);

    return 0;
}
