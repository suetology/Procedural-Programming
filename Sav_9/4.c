#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    double x, y;
} Point;  

void printPoint(Point p);
Point createPoint(double x, double y);
double getDistance(Point a, Point b);

typedef struct List {
    Point value; 
    struct List *next;
} List;

List *createList(Point value);
void printList(List *list);
int getListSize(List *list);
void insertElement(List **list, Point value);
Point getElement(List *list);
Point deleteElement(List **list);
void destroyList(List **list);

int main() {
    List *list = createList(createPoint(1.0, 2.0));
    insertElement(&list, createPoint(3.0, 4.0));
    insertElement(&list, createPoint(5.0, 6.0));
    insertElement(&list, createPoint(7.0, 8.0));
    printList(list);    

    deleteElement(&list);
    printList(list);

    destroyList(&list);
    printList(list);

    return 0;
}

void printPoint(Point p) {
    printf("(%lf, %lf)", p.x, p.y);
}

Point createPoint(double x, double y) {
    Point p = { x, y };
    return p;
}

double getDistance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

List *createList(Point value) {
    List *node = malloc(sizeof(List));
    node->value = value;
    node->next = NULL;
}

void printList(List *list) {
    if (list) {
        printPoint(list->value);
        putchar('\n');
        printList(list->next);
    }
}

int getListSize(List *list) {
    if (list) {
        return 1 + getListSize(list->next);
    }
    return 0;
}

void insertElement(List **list, Point value) {
    List *new = createList(value);
    new->next = *list;
    *list = new;
}

Point getElement(List *list) {
    return list->value;
}

Point deleteElement(List **list) {
    Point deleted = getElement(*list);
    List *node = *list;
    *list = (*list)->next;
    free(node);
    return deleted;
}

void destroyList(List **list) {
    while (*list) {
        List *node = *list;
        *list = (*list)->next;
        free(node);
    }
}