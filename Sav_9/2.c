#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *data;
    int size;
} Stack;

void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);  
int top(Stack *stack);
void destroyStack(Stack *stack);

int main() {
    Stack *stack = malloc(sizeof(Stack*));
    initStack(stack);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    pop(stack);
    printStack(stack);
    destroyStack(stack);
    push(stack, 4);
    printStack(stack);

    return 0;
}

void initStack(Stack *stack) {
    stack->data = NULL;
    stack->size = 0;
}

void printStack(Stack *stack) {
    for (int i = 0; i < stack->size; ++i) {
        printf("%d ", stack->data[i]);
    }
}

int getStackSize(Stack *stack) {
    return stack->size;
}

void push(Stack *stack, int value) {
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

int pop(Stack *stack) {
    int t = top(stack);
    stack->data = realloc(stack->data, stack->size - 1);
    stack->size--;
    return t;
}

int top(Stack *stack) {
    if (!stack->size) {
        return 0;
    }
    return stack->data[stack->size - 1];
}

void destroyStack(Stack *stack) {
    free(stack->data);
    stack->data = NULL;
    stack->size = 0;
}