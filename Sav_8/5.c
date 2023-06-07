#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int init(char ****data, int n, int m);
void set(char ****data, int i, int j, const char *content);
char* get(char ****data, int i, int j);
void delete(char ****data, int n, int m);

int main() {
    char ***data;
    int w = 4, h = 10;

    init(&data, h, w);
    set(&data, 2, 2, "Hello world");
    printf("%s", get(&data, 2, 2)); 

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            printf("%s ", data[i][j]);
        }
    }

    delete(&data, h, w);

    return 0;
}

int init(char ****data, int n, int m) {
    if (n == 0 || m == 0) {
        return -1;
    }
    *data = malloc(n * sizeof(char **));

    for (int i = 0; i < n; ++i) {
        (*data)[i] = malloc(m * sizeof(char *));
        for (int j = 0; j < m; ++j) {
            (*data)[i][j] = NULL;
        }
    }
}

void set(char ****data, int i, int j, const char *content) {
    (*data)[i][j] = malloc(strlen(content) + 1);
    strcpy((*data)[i][j], content);
}

char* get(char ****data, int i, int j) {
    return (*data)[i][j];
}

void delete(char ****data, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            free((*data)[i][j]);
        }
        free((*data)[i]);
    }
    free(*data);
}