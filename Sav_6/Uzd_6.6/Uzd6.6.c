#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_CAPACITY 20
#define TEXT_CAPACITY 10000

int findWord(char *word, char *fileBuffer, FILE *readF, FILE *appendF);
void commitError(char *word, FILE *errorsF, int lineN, int wordN);

int main() {
    printf("The program that can store\n");
    char wordBuffer[WORD_CAPACITY];
    char textBuffer[TEXT_CAPACITY];
    char fileBuffer[TEXT_CAPACITY];

    FILE* text = fopen("text.txt", "r");
    FILE* dictionaryRead = fopen("dictionary.txt", "r");
    FILE* dictionaryAppend = fopen("dictionary.txt", "a");
    FILE* errorsFile = fopen("errors.txt", "w");
    if (!text || !dictionaryAppend || !dictionaryRead || !errorsFile) {
        return 1;   
    }
    
    int lineN = 1, wordN = 1;
    while (fgets(textBuffer, TEXT_CAPACITY, text) != NULL) {
        int j = 0;
        int length = strlen(textBuffer);
        if (length < 2) {
            continue;
        }
        for (int i = 0; i <= length; i++) {
            if (textBuffer[i] == ' ' || textBuffer[i] == '\n') {
                wordBuffer[j] = ' ';
                wordBuffer[j + 1] = '\0';
                j = 0;
                if (findWord(wordBuffer, fileBuffer, dictionaryRead, dictionaryAppend) == 1) {
                    commitError(wordBuffer, errorsFile, lineN, wordN);
                }   
                wordN++;
            } else {
                wordBuffer[j] = textBuffer[i];
                j++;
            }    
        }
        wordN = 1;
        lineN++;
    }
    
    fclose(errorsFile);
    fclose(dictionaryAppend);
    fclose(dictionaryRead);
    fclose(text);
    return 0;
}

int findWord(char *word, char *fileBuffer, FILE *readF, FILE *appendF) {
    fgets(fileBuffer, TEXT_CAPACITY, readF);
    if (strstr(fileBuffer, word) == NULL) {
        printf("\"%s\" word is not present in the dictionary. Type \"y\" if you want to add it and type any other symbol if not:\n", word);
        char answer;
        scanf("%c", &answer);

        while (getchar() != '\n')
            ;

        if (answer == 'y') {
            fputs(word, appendF);
            return 0;   
        } else {
            return 1;
        }
    }
    return 0;
}

void commitError(char *word, FILE *errorsF, int lineN, int wordN) {
    fputs(word, errorsF);
    fprintf(errorsF, "[line %d:%d]\n", lineN, wordN);
}