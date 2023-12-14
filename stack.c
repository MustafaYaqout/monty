#include "stack.h"

void push(stack_t** top, int n) {
    stack_t* newNode = malloc(sizeof(stack_t));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }

    newNode->data = n;
    newNode->next = *top;
    *top = newNode;
}