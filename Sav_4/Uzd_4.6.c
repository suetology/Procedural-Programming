#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    printf("The program find the longest number in your entered sequence\n");
    printf("Enter sequence and write non-positive number when you are finished:\n");
    char str[10], longest[10]; 
    double n;
    int length, maxLength = 0;

    scanf("%s", str); 
    n = strtod(str, NULL);
    while (n > 0) {
        if (floor(n) != n) {
            length = strlen(str) - 1;
        } else {
            length = strlen(str);
        }
        
        if (length > maxLength) {
            maxLength = length;
            strcpy(longest, str);
        }
        scanf("%s", str); 
        n = strtod(str, NULL);
    }   

    printf("The longest number in your sequence is: %s - %d\n", longest, maxLength);
    return 0;
}