#include <stdio.h>
#include <assert.h>

size_t strlen(char *string);
void test_strlen(char *string, size_t expectedSize);

int main() {
    test_strlen("hello world", 11);
    test_strlen("abc", 3);
    test_strlen("@&@&&^@", 7);
    test_strlen("a\n\n\n\n\n\t", 7);
    test_strlen("", 0);

    printf("All the tests passed successfully!\n");

    return 0;
}

size_t strlen(char *string) {
    int i;
    for (i = 0; string[i] != '\0'; ++i)
        ;
    return i;
}

void test_strlen(char *string, size_t expectedSize) {
    assert(strlen(string) ==  expectedSize);
}