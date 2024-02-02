#include "monty.h"
/**
 * push - push command
 * @stack: The stack address
 * @val: The value to be pushed
 * Description: This function permits to push a node at the top of the stack.
 * Return: The added stack
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
