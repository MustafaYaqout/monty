#include "stack.h"

void execute_instruction(stack_t **stack, char *opcode, int value, unsigned int line_number) {
    if (strcmp(opcode, "push") == 0) {
        push(stack, value);
    } else if (strcmp(opcode, "pint") == 0) {
        pint(*stack);
    } else {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}
