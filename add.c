#include "monty.h"
/**
 * pint -
 */
void add(stack_t **stack, int line_number)
{
    stack_t *tmp;
    if ((*stack) == NULL || (*stack)->next == NULL)
    {
        printf("L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    tmp = (*stack)->next;
    tmp->n = (*stack)->n + tmp->n;
    pop(stack, line_number);
}
