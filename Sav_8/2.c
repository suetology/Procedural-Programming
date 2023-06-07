#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* biggestFile(int argc, char *argv[]);
long getFileSize(char *filename);

int main(int argc, char *argv[]) {
    char *bf = biggestFile(argc, argv); 
    printf("%s", bf);
    free(bf);
    return 0;
}

char* biggestFile(int argc, char *argv[]) {
    if (argc < 2) {
        return NULL;
    }
    char *biggestFile = malloc(30); 
    long max = 0;
    for (int i = 1; i < argc; i++) {
        long cur = getFileSize(argv[i]);
        if (cur > max) {
            strcpy(biggestFile, argv[i]);
            max = cur;
        }
    }
    return biggestFile;
}

long getFileSize(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return 0;
    }
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);
    return size;
}