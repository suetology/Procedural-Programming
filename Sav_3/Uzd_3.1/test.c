#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LinkedList {
    char data[30];
    int id;
    struct LinkedList* next;
};

struct LinkedList* Remove(struct LinkedList* node) {
    if (node->next) {
        return (struct LinkedList*) node->next;
    } else {
        return (struct LinkedList*) NULL;
    }
}

struct LinkedList* Add(struct LinkedList* node, char* data, int id) {
    node->next = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    strcpy(node->next->data, data);
    node->next->id = id;
    node->next->next = NULL;
    return node;
}

struct LinkedList* CheckPresence(struct LinkedList* node, char* data, int id) {  
    if (strcmp(data, node->data) == 0) {
        return Remove(node);
    }
    if (node->next) {
        node->next = CheckPresence(node->next, data, id);
        return node;
    } else {
        return Add(node, data, id);
    }
}

void Print(struct LinkedList* node) {
    printf("%s\n", node->data);
    if (node->next) {
        Print(node->next);
    }
}

int main() {
    struct LinkedList* head = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    strcpy(head->data, "Hujman");
    head->id = 0;
    head->next = NULL;

    head = CheckPresence(head, "Body", 1);
    head = CheckPresence(head, "Legs", 2);
    head = CheckPresence(head, "Feet", 3);

    Print(head);

    head = CheckPresence(head, "Body", 1);
    head = CheckPresence(head, "Legs", 2);
    head = CheckPresence(head, "Feet", 3);
    


    return 0;
}