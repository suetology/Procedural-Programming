#include <stdio.h>

#define MAX_ERRORS 10
#define CAPACITY 12

int checkDate(char *date, int *y, int *m, int *d);
int findWeekDay(int y, int m, int d);

int main() {
    printf("The program checks what day of week was this date\n");
    printf("Enter the date in format YYYY-MM-DD:\n");
    char date[CAPACITY];
    int y, m, d;
    int success = 1;
    do {
        if (!success) {
            printf("Enter the valid date in format YYYY-MM-DD!\n");
        }
        scanf("%s", date);
        while (getchar() != '\n')
            ;
        success = checkDate(date, &y, &m, &d);
    } while (!success);

    FILE *file = fopen("week.txt", "r");

    if (!file) {
        printf("File \"week.txt\" is not found!\n");
        return 1;
    }

    int wd = findWeekDay(y, m, d);
    char day[10];

    for (int i = 0; i < wd; i++) {
        fscanf(file, "%s", day);
    }
    
    printf("%s", day);

    return 0;
}

int checkDate(char *date, int *y, int *m, int *d) {
    if (sscanf(date, "%d-%d-%d", y, m, d) < 3) {
        return 0;
    }
    if (*y < 1000 || *y > 9999 || *m < 1 || *m > 12) {
        return 0;
    } 
    if (*d > 31 || 
        *m == 2 && *d > 29 || 
        (*m == 4 || *m == 6 || *m == 9 || *m == 11) && *d > 30) {
        return 0;
    }
    return 1;
}

int findWeekDay(int y, int m, int d) {
    int wd = (d + ((153 * (m + 12 * ((14 - m) / 12) - 3) + 2) / 5)
               + (365 * (y + 4800 - ((14 - m) / 12)))
               + ((y + 4800 - ((14 - m) / 12)) / 4)
               - ((y + 4800 - ((14 - m) / 12)) / 100)
               + ((y + 4800 - ((14 - m) / 12)) / 400)
               - 32045) % 7;
    return wd + 1;
}