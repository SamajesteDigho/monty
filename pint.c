#include "monty.h"
/**
 * pint -
 */
void pint(stack_t *stack, int line_number)
{
    
    if (stack != NULL)
    {
        printf("%d\n", stack->n);
    }
    else
    {
        printf("L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
}
