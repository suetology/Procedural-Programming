#include <stdio.h>
#include <stdlib.h>

long long Pow(int base, int power);
long long ToBinary(int n);

int main()
{
    printf("%s", "a:\n");
    printf("%d%c", 0b11011, '\n');
    printf("%d%c", 0b10010100, '\n');
    printf("%d%c", 0b11001011010101, '\n');

    printf("%s", "b:\n");
    printf("%lld%c", ToBinary(37), '\n');
    printf("%lld%c", ToBinary(241), '\n');
    printf("%lld%c", ToBinary(2487), '\n');

    printf("%s", "c:\n");
    printf("%d%c", 0x6E2, '\n');
    printf("%d%c", 0xED33, '\n');
    printf("%d%c", 0x123456, '\n');

    printf("%s", "d:\n");
    printf("%x%c", 243, '\n');
    printf("%x%c", 2483, '\n');
    printf("%x%c", 4612, '\n');

    return 0;
}

long long Pow(int base, int power) {
    long long result = 1;
    while(power > 0) {
        result *= base;
        power--;
    }
    return result;
}

long long ToBinary(int n) {
    long long result = 0;
    for(int i = 0; n > 0; i++) {
        result += (n % 2) * Pow(10, i);
        n /= 2;
    }
    return result;
}
