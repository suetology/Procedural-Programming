#include <stdio.h>
#include <stdlib.h>

#define bool char
#define false 0
#define true 1

struct LinkedList {
    int value;
    struct LinkedList *next;
};

struct LinkedList *addToList(struct LinkedList* head, int value);
void printList(struct LinkedList* head);

bool isPrime(int n);

int main() {
    printf("The program that finds all the prime numbers in your entered sequence of positive numbers\n");

    printf("Input your sequence and enter a non-positive number when you are finished:\n");
    int n, success = 1;
    struct LinkedList *head = NULL;

    do {
        do {
            if (!success) {
                printf("Enter a NUMBER!\n");
            }
            success = scanf("%d", &n);
            while (getchar() != '\n')
                ;
        } while (!success);

        if (isPrime(n) && n > 0) {
            head = addToList(head, n);
        }

    } while (n > 0);

    if (head) {
        printf("Prime numbers of your sequence:\n");
        printList(head);
    } else {
        printf("There were no prime numbers in your sequence!\n");
    }

    return 0;
}

struct LinkedList *addToList(struct LinkedList* head, int value) {
    if (head) {
        if (head->value == value) {
            return head;
        } 
        head->next = addToList(head->next, value);
        return head;
    }
    head = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    head->value = value;
    head->next = NULL;
    return head;
}

void printList(struct LinkedList* head) {
    printf("%d\n", head->value);
    if (head->next) {
        printList(head->next);
    }
}

bool isPrime(int n) {
    if (n == 1) {
        return false;
    }
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}