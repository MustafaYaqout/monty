#include "stack.h"

int main(int argc, char *argv[]) {
    FILE *file;
    char line[100];
    unsigned int line_number = 0;

    stack_t *stack = NULL;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open the file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        char opcode[10];
        int value;

        line_number++;

        if (line[0] == '\n' || line[0] == '#' || line[0] == ' ') {
            continue;
        }

        if (sscanf(line, "%s %d", opcode, &value) == 2) {
            execute_instruction(&stack, opcode, value, line_number);
        } else {
            fprintf(stderr, "L%u: Invalid instruction\n", line_number);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    return 0;
}
