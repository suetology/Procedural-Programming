#include <stdio.h>

long getFileSize(char *filename);

int getValue(FILE *file, int index);
void setValue(FILE *file, int index, int value);
void addValue(FILE *file, int index, int value);
void remValue(FILE *file, int index);

int main() {
    FILE *file = fopen("text.bin", "a+");
    if (!file) {
        return 1;
    }
    //printf("%c", getValue(file, 3));
    setValue(file, 0, 999);

    fclose(file);
    return 0;
}

long getFileSize(char *filename) {
    FILE *file = fopen(filename, "a+");
    if (!file) {
        return 0;
    }
    fseek(file, 0, SEEK_END);
    return ftell(file);
}

int getValue(FILE *file, int index) {
    int n;
    fseek(file, index, SEEK_SET);
    //fscanf(file, "%d", &n);
    n = fgetc(file);
    return n;
}

void setValue(FILE *file, int index, int value) {
    fseek(file, index, SEEK_SET);
    fprintf(file, "%d", value);
}

void addValue(FILE *file, int index, int value) {

}

void remValue(FILE *file, int index) {

}