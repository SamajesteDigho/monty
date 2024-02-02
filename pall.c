#include "monty.h"
/**
 * pall -
 */
void pall(stack_t *stack)
{
    stack_t *tmp;
    tmp = stack;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}
