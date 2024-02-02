#include "monty.h"
/**
 * main - Entry point
 */
int main(int argc, char **argv)
{
    FILE *file;
    int l_nb = 1;
    char line[BUFFER_SIZE];
    char operation[BUFFER_SIZE];
    char op_code[OP_SIZE];

    /* Initialize the stack */
    stack_t *stack = (stack_t *) malloc(sizeof(stack_t));
    stack = NULL;
    /* Check command synthax */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* Open file and check existence */
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Go through the lines */
    while (fgets(line, sizeof(line), file))
    {
        trim_line(operation, line);
        strncpy(op_code, operation, OP_SIZE);
        op_code[OP_SIZE] = '\0';
        if (valid_operation(op_code) > 0)
        {
            execute_operation(&stack, operation, l_nb);
        }
        else
        {
            printf("L%d: unknown instruction %s\n", l_nb, op_code);
            exit(EXIT_FAILURE);
        }
        l_nb++;
        memset(line, 0, sizeof(line));
        memset(operation, 0, sizeof(operation));
        memset(op_code, 0, sizeof(op_code));
    }
    return (0);
}