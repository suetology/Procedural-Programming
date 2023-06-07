#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

typedef struct Point {
    double x, y;
} Point;  

void printPoint(Point p);
Point createPoint(double x, double y);
double getDistance(Point a, Point b);

typedef struct Stack {
    Point *data;
    int size;
} Stack;

void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, Point value);
Point pop(Stack *stack);  
Point top(Stack *stack);
void destroyStack(Stack *stack);

int main() {
    Stack *stack = malloc(sizeof(Stack*));
    initStack(stack);
    push(stack, createPoint(3.0, 4.0));
    push(stack, createPoint(0.0, 0.0));
    push(stack, createPoint(-3.0, -4.0));
    push(stack, createPoint(10.0, 10.0));
    push(stack, createPoint(0.0, 3.0));
    printStack(stack);

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

void initStack(Stack *stack) {
    stack->data = NULL;
    stack->size = 0;
}

void printStack(Stack *stack) {
    for (int i = 0; i < stack->size; ++i) {
        printf("Distance from (0, 0) to");
        printPoint(stack->data[i]);
        printf(" is equal to %lf\n", getDistance(createPoint(0.0, 0.0), stack->data[i]));
    }
}

int getStackSize(Stack *stack) {
    return stack->size;
}

void push(Stack *stack, Point value) {
    if (!stack->size) {
        stack->data = malloc(sizeof(stack->data));
        stack->data[0] = value;
        stack->size++;
        return;
    }
    stack->data = realloc(stack->data, stack->size + 1);
    stack->data[stack->size] = value;
    stack->size++;
}

Point pop(Stack *stack) {
    Point t = top(stack);
    stack->data = realloc(stack->data, stack->size - 1);
    stack->size--;
    return t;
}

Point top(Stack *stack) {
    if (!stack->size) {
        return createPoint(0.0, 0.0);
    }
    return stack->data[stack->size - 1];
}

void destroyStack(Stack *stack) {
    free(stack->data);
    stack->data = NULL;
    stack->size = 0;
}