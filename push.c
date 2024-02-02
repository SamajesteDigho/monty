#include "monty.h"
/**
 * push -
 */
stack_t *push(stack_t **stack, int val)
{
    stack_t *new;
    new = (stack_t *) malloc(sizeof(stack_t));
    if (new == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new->n = val;
    if ((*stack) == NULL)
    {
        new->next = NULL;
        new->prev = NULL;
        *stack = new;
        return (new);
    }
    new->next = (*stack);
    new->prev = NULL;
    (*stack)->prev = new;
    (*stack) = new;
    return (new);
}
