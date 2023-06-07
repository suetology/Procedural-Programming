#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List {
    struct List *next;
    struct List *prev;
    int count;
    int *dataCount;
    char ***data;
} List;

List *createList(char ***data, int c, int *n);
void insertNode(List **list, List **new);
void insertArray(List **node, char **data, int c);
void insertString(List **node, char *string, int n);
void sortArray(List **node, int n);
int getNodeCount(List *node);
void insertNodeSorted(List **list, List *newNode);
void sortList(List **list);
void destroyNode(List **node);
void destroyList(List **list);
void printNode(List *node);
void printList(List *node);

int main() {
    char *set[] = { "hello", " ", "world", " ", "shesh", " ", "beep" };

    char ***data = malloc(sizeof(char**));
    data[0] = set;
    int n[1] = { 7 };

    List *list = createList(data, 1, n);

    

    printList(list);
    printf("\n");
    destroyNode(&list);

    return 0;
}

List *createList(char ***data, int c, int *n) {
    List *node = malloc(sizeof(List));
    node->next = NULL;
    node->prev = NULL;
    node->count = c;
    node->dataCount = malloc(c * sizeof(int));
    node->data = malloc(c * sizeof(char**));

    for (int i = 0; i < c; ++i) {
        node->dataCount[i] = n[i];
        node->data[i] = malloc(n[i] * sizeof(char*));

        for (int j = 0; j < n[i]; ++j) {
            node->data[i][j] = malloc(strlen(data[i][j]) + 1);
            memcpy(node->data[i][j], data[i][j], strlen(data[i][j]) + 1);
        }   
    }
    return node;    
}

void insertNode(List **list, List **new) {
    if (!(*list) || !(*new)) {
        return;
    }
    (*new)->next = *list;
    (*list)->prev = *new;
    *list = *new;
}

void insertArray(List **node, char **data, int c) {
    if (!(*node)) {
        return;
    }
    (*node)->count++;
    (*node)->dataCount = realloc((*node)->dataCount, sizeof(int) * (*node)->count);
    (*node)->dataCount[(*node)->count - 1] = c;
    (*node)->data[(*node)->count - 1] = malloc(c * sizeof(char**));
    for (int i = 0; i < c; ++i) {
        (*node)->data[(*node)->count - 1][i] = malloc(strlen(data[i]) + 1);
        memcpy((*node)->data[(*node)->count - 1][i], data[i], strlen(data[i]) + 1);
    }
}

void insertString(List **node, char *string, int n) {
    if (!(*node)) {
        return;
    }
    int i = (*node)->dataCount[n];
    (*node)->data[n] = realloc((*node)->data[n], (i + 1) * sizeof(char*));
    (*node)->data[n][i] = malloc(strlen(string) + 1);
    memcpy((*node)->data[n][i], string, strlen(string) + 1);
    (*node)->dataCount[n]++;
}

void sortArray(List **node, int n) {
    if (!(*node)) {
        return;
    }
    char temp[30];

    for (int i = 0; i < (*node)->dataCount[n]; ++i) {
        for (int j = 0; j < (*node)->dataCount[n] - 1 - i; ++j) {
            if (strcmp((*node)->data[n][j], (*node)->data[n][j + 1]) > 0) {
                strcpy(temp, (*node)->data[n][j]);
                strcpy((*node)->data[n][j], (*node)->data[n][j + 1]);
                strcpy((*node)->data[n][j + 1], temp);
            }
        }
    }
}

int getNodeCount(List *node) {
    if (!node) {
        return -1;
    }
    int count = 0;
    for (int i = 0; i < node->count; ++i) {
        count += node->dataCount[i];
    }
}

void insertNodeSorted(List **list, List *newNode) {
    if (!newNode) {
        return;
    }
    if (*list == NULL) {
        *list = newNode;
    } else if (getNodeCount(*list) >= getNodeCount(newNode)) {
        (*list)->prev = newNode;
        newNode->next = *list;
        *list = newNode;
    } else {
        List *current = *list;

        while (current->next != NULL && getNodeCount(current->next) < getNodeCount(newNode)) {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next = newNode;    
        if (newNode->next) {
            newNode->next->prev = newNode;
        }
    }
}

void sortList(List **list) {
    if (!(*node)) {
        return;
    }
    List *sorted = NULL;

    List *current = *list;
    while (current) {
        List *next = current->next;
        current->next = NULL;
        current->prev = NULL;

        insertNodeSorted(&sorted, current);

        current = next;
    }
    *list = sorted; 
}

void destroyNode(List **node) {
    if (!(*node)) {
        return;
    }
    for (int i = 0; i < (*node)->count; ++i) {
        for (int j = 0; j < (*node)->dataCount[i]; ++j) { 
            free((*node)->data[i][j]);
        }
        free((*node)->data[i]);
    }
    free((*node)->data);
    free((*node)->dataCount);

    if ((*node)->next) {
        (*node)->next->prev = NULL;
    }
    if ((*node)->prev) {
        (*node)->prev->next = NULL;
    }
    free(*node);
}

void destroyList(List **list) {

}

void printNode(List *node) {
    if (!node) {
        return;
    }
    for (int i = 0; i < node->count; ++i) {
        for (int j = 0; j < node->dataCount[i]; ++j) {
            printf("%s", node->data[i][j]);
        }    
    }
}

void printList(List *node) {
    if (!node) {
        return;
    }
    while (node->prev) {
        node = node->prev;
    }
    while (node) {
        printNode(node);
        node = node->next;
    }
}