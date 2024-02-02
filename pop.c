#include "monty.h"
/**
 * pop - Remove first
 * @stack: Stack concerned
 * @line_number: The line number in the monty file
 * Description: Removes the first element in a stack if not empty
 */
void pop(stack_t **stack, int line_number)
{
stack_t *tmp;
if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
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
