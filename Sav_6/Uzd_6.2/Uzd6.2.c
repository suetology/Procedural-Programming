#include <stdio.h>

#define CAPACITY 10

int power(int n, int p);
int toNumber(char n);

int main() {
    printf("The program finds the length of the number in file \nThe number should be in range [10; 1000] and it should have no more than 3 digits after comma\n");
    printf("Checking file \"in.txt\"...\n");

    char filename[256] = "in.txt";
    int error;

    do {
        FILE *file = fopen(filename, "r");
        char buffer[CAPACITY];

        if (!file) {
            printf("File %s does not exist!\n", filename);
            return 1;
        }
        if (fgets(buffer, CAPACITY, file) == 0) {
            printf("Failed to read a file %s!\n", filename);
            return 2;
        }

        error = 0;
        int comma = 0;
        int length = 0;
        double value = 0;
        for (int i = 0; i < CAPACITY && buffer[i] > 32; i++) {
            int n = toNumber(buffer[i]);
            if (n != -1) {
                if (!comma) {
                    value = value * 10 + n;
                    length++;
                } else if (comma && i - comma <= 3) {
                    value += (double)n / power(10, i - comma);
                    length++;
                } else {
                    error = 1;
                    break;
                }
            } else if (buffer[i] == ',') {
                comma = i;
            } else {
                error = 2;
                break;
            }
        }
        if (value > 1000 || value < 10) {
            error = 3;
        }
        if (error) {
            switch (error)
            {
            case 1:
                printf("The number should not have more than 3 digits after comma\n");
                break;
            case 2:
                printf("File should contain a number from range [10; 1000] which have no more than 3 digits after comma\n");
                break;
            case 3:
                printf("The number should be from range [10; 1000]\n");
                break;
            }
            printf("Enter the name of the new file:\n");
            scanf("%s", filename);
        } else {
            printf("The length of the number in the file is %d\n", length);
        }

        fclose(file);
    } while (error);

    return 0;
}

int power(int n, int p) {
    int r = 1;
    while (p-- > 0) {
        r *= n;
    }
    return r;
}

int toNumber(char n) {
    if (n >= 48 && n <= 57) {
        return n - 48;
    }
    return -1;
}
