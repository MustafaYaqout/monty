#include "stack.h"
/**
 * pop - prints the top
 * @top: stack head
 * @n: line_number
 * Return: no return
*/
void pop(stack_t **top, int n)
{
    stack_t *p;

    if (p == NULL)
    {
        fprintf(stderr,"%d:can't pop an empty stack\n",n);
        fclose(bus.file);
		free(bus.content);
		free_stack(*top);
        exit(EXIT_FAILURE);
    }
    p = *top;
    *top = p->next;
    free(p);
}