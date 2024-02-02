#include "monty.h"
/**
 * pint -
 */
void swap(stack_t **stack, int line_number)
{
    stack_t *tmp;
    int cur;
    if (*stack == NULL || (*stack)->next == NULL)
    {
        printf("L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    tmp = (*stack)->next;
    cur = tmp->n;
    tmp->n = (*stack)->n;
    (*stack)->n = cur;
}
