#include <stdio.h>
#include <assert.h> 

size_t strlen(char *string);

int strcmp(char *str1, char *str2);
void test_strcmp(char *str1, char *str2, int value);

char *strcpy(char *destination, const char *source);
void test_strcpy(char *stringToCopy);

int main() {
    test_strcmp("", "", 0);
    test_strcmp("\n", "\n", 0);
    test_strcmp("abc", "bc", -1);
    test_strcmp("add", "abb", 2);

    test_strcpy("abc");
    test_strcpy("");
    test_strcpy("\n");

    printf("All the tests passed successfully!\n");

    return 0;
}

size_t strlen(char *string) {
    int i;
    for (i = 0; string[i] != '\0'; ++i)
        ;
    return i;
}

int strcmp(char *str1, char *str2) {
    int l1 = strlen(str1);
    int l2 = strlen(str2);

    for (int i = 0; i < l1 && i < l2; ++i) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
    }
    return 0;
}

void test_strcmp(char *str1, char *str2, int value) {
    assert(strcmp(str1, str2) == value);
}

char *strcpy(char *destination, const char *source) {
    int i;
    for (i = 0; source[i] != '\0'; ++i) {
        destination[i] = source[i];
    }
    destination[i] = '\0';
    return destination;
}

void test_strcpy(char *stringToCopy) {
    size_t len = strlen(stringToCopy);
    char str[len];
    strcpy(str, stringToCopy);
    assert(strcmp(str, stringToCopy) == 0);
}