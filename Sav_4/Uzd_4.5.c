#include <stdio.h>

#define INT_MAX 2147483647

int main() {
    printf("The program finds the sum, average, minimum and maximum values of your sequence of positive numbers\n");
    
    printf("Enter the size of your sequence:\n");
    int n;
    scanf("%d", &n);

    if (n < 1) {
        printf("Size of sequence should be positive!\n");
        return 0;
    }

    int current;
    int max = 0, min = INT_MAX, sum = 0;
    float average;

    for (int i = 0; i < n; i++) {
        printf("Enter number #%d: ", i + 1);
        scanf("%d", &current);

        sum += current;

        if (current > max) {
            max = current;
        }
        if (current < min) {
            min = current;
        }
    }
    average = (float)sum / n;

    printf("The sum of your sequence is %d\n", sum);
    printf("The average of your sequence is %f\n", average);
    printf("The minimum value of your sequence is %d\n", min);
    printf("The maximum value of your sequence is %d\n", max);
}