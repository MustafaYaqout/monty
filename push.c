#include "stack.h"
/**
 * push - prints the top
 * @top: stack head
 * @n: line_number
 * Return: no return
*/

void push(stack_t **top, int n) {
    stack_t* newNode = malloc(sizeof(stack_t));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }

    newNode->data = n;
    newNode->next= *top;
    *top = newNode;
}