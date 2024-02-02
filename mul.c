#include "monty.h"
/**
 * sub - Subtract top 2 node values
 * @stack: The stack
 * @line_number: The line of command in file
 * Description: Permits to subtract the first 2 nodes and store to 2nd node.
 */
void mul(stack_t **stack, int line_number)
{
stack_t *tmp;

if ((*stack) == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
tmp = (*stack)->next;
tmp->n = tmp->n * (*stack)->n;
pop(stack, line_number);
}
