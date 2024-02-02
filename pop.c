#include "monty.h"
/**
 * pint -
 */
void pop(stack_t **stack, int line_number)
{
    stack_t *tmp;
    if (*stack == NULL)
    {
        printf("L%d: can't pop an stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    tmp = *stack;
    (*stack) = tmp->next;
    if (tmp->next != NULL)
    {
        tmp->next->prev = NULL;
    }
    tmp->next = NULL;
    tmp->prev = NULL;
    free(tmp);
}
