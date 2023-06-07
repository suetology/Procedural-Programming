#include <stdio.h>

long getFileSize(char *fileName);

int main() {
    printf("%ld\n", getFileSize("text.txt"));

    return 0;
}

long getFileSize(char *fileName) {
    FILE* file = fopen(fileName, "rb");
    if (!file) {
        return 0;
    }
    fseek(file, 0, SEEK_END);
    return ftell(file);
}