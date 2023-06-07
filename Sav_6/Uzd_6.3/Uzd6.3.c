#include <stdio.h>

#define CAPACITY 100

double findAverage(double a, double b, double c);
int power(int n, int p);
int toNumber(char n);

int main() {
    printf("The program gets the number with the average value out of three entered numbers\n");
    printf("Enter three numbers without spaces and split them using \";\" sign\n");
    int error = 0;
    double a, b, c;

    do {
        if (error) {
            printf("Your input is wrong, try again: \n");
        }
        error = 0;
        a = 0, b = 0, c = 0;
        char buffer[CAPACITY];
        double *current = &a;
        scanf("%s", buffer);
        int sign = 0;
        int dot = 0;   

        for (int i = 0; i < CAPACITY && buffer[i] != 0; i++) {
            int n = toNumber(buffer[i]);
            if (n != -1) {
                if (!dot) {
                    (*current) = (*current) * 10 + n;
                } else { 
                    (*current) += (double)n / power(10, dot);
                    dot++;
                }
            } else if (buffer[i] == '.') {
                dot = 1;
            } else if (buffer[i] == ';') {
                if (sign == 1) {
                    (*current) = -(*current);
                }
                sign = 0;
                dot = 0;
                if (current == &a) {
                    current = &b;
                } else {
                    current = &c;
                }
            } else if (!sign && buffer[i] == '-') {
                sign = 1;
            } else if (!sign && buffer[i] == '+') {
                sign = 2;
                continue;
            } else {
                error = 1;
                break;
            }
        }
        if (sign == 1) {
            (*current) = -(*current);
        }
    } while (error);

    double av = findAverage(a, b, c);

    printf("Enter the name of file where you want to store the answer:\n");
    error = 0;
    do {
        if (error) {
            printf("Failed writing to file. Enter the filename again:\n");
            error = 0;
        }
        char filename[20];
        scanf("%s", filename);
        int txt = 0;

        for (int i = 20; i >= 0; i--) {
            if (filename[i] == 't'  && i > 3) {
                txt = filename[i - 1] == 'x' && filename[i - 2] == 't' && filename[i - 3] == '.';
                break;
            }
        }
        if (!txt) {
            error = 1;
            continue;
        }
        
        FILE *file = fopen(filename, "w");
        if (!file) {
            error = 2;
            continue;
        }
        fprintf(file, "%lf", av);

    } while (error);
}

double findAverage(double a, double b, double c) {
    if (a >= b) {
        if (b >= c) return b;
        if (a >= c) return c;
        return a;
    } else {
        if (a >= c) return a;
        if (b >= c) return c;
        return b;
    }
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