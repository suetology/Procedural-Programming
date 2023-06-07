#include <stdio.h>

int main() {
    printf("The program that creates an array with n elements and finds all the pairs of elements that satisfy the condition: (Xi, Xy: Xi * Xy = s), where s, n and the elements of the array are your entered numbers\nP.S. all the elements of the array should be positive!\n");
    int s, n;
    printf("Enter s number:\n");
    scanf("%d", &s);
    printf("Enter n number:\n");
    scanf("%d", &n);

    if (n < 2) {
        printf("n should be at least 2!\n");
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element #%d:\n", i + 1);
        int success = 1;
        do {
            if (!success) {
                printf("You should enter a POSITIVE NUMBER!\n");
            } 
            success = (scanf("%d", &arr[i])) && (arr[i] > 0);
            while (getchar() != '\n')
                ;
        } while (!success);
    }
    printf("All the elements entered successfully!\n");

    printf("The pairs of the elements which when multiplied are equal to %d:\n", s);
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] * arr[j] == s) {
                count++;
                printf("(%d, %d)\n", arr[i], arr[j]);
            }
        }
    }
    if (count == 0) {
        printf("Unfortunately, there are no such pairs :(\n");
    }

    return 0;
}