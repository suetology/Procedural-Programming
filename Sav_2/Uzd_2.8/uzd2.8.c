#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Pow(int number, int power);
int ConvertToInt(char c);
char ConvertToChar(int n);
int GetLength(char* n);

int main()
{
    printf("Enter the system (2 / 10 / 16) of your initial number: ");
    int from;
    scanf("%d", &from);

    printf("Enter the system (2 / 10 / 16) you want to convert to: ");
    int to;
    scanf("%d", &to);

    printf("Enter your number: ");
    char n[20] = { ' ' };
    scanf("%s", n);
    int l = GetLength(n);

    int value = 0;
    for (int i = l - 1; i >= 0; i--) {
        value += ConvertToInt(n[i]) * Pow(from, l - i - 1);
    }

    l = 0;
    int v = value;
    while (v > 0) {
        v /= to;
        l++;
    }

    char result[20] = { ' ' };

    for(int i = l - 1; i >= 0; i--) {
        result[i] = ConvertToChar(value % to);
        value /= to;
    }
    printf("%s", result);

    return 0;
}

int Pow(int number, int power) {
    int result = 1;
    while(power > 0) {
        result *= number;
        power--;
    }
    return result;
}
int ConvertToInt(char c) {
    if (c >= 48 && c <= 57) {         // check if char is between 0 - 9
        return c - 48;
    } else if (c >= 65 && c <= 70) {  // check if char is between A - F
        return c - 55;
    } else if (c >= 97 && c <= 102) { // check if char is between a - f
        return c - 87;
    }
    return 0;
}

char ConvertToChar(int n) {
    if (n >= 0 && n <= 9) {
        return n + 48;
    } else if (n >= 10 && n <= 16) {
        return n + 55;
    }
    return 0;
}


int GetLength(char* n) {
    int i = 0;
    while (n[i] != 0) {
        i++;
    }
    return i;
}
