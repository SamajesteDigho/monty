#include "monty.h"
/**
 * mod - Mode top 2 node values
 * @stack: The stack
 * @line_number: The line of command in file
 * Description: Permit to find mode of the first 2 nodes and store to 2nd node
 */
void mod(stack_t **stack, int line_number)
{
stack_t *tmp;

if ((*stack) == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
if ((*stack)->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
exit(EXIT_FAILURE);
}

tmp = (*stack)->next;
tmp->n = tmp->n % (*stack)->n;
pop(stack, line_number);
}
