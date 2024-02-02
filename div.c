#include "monty.h"
/**
 * div - Divide top 2 node values
 * @stack: The stack
 * @line_number: The line of command in file
 * Description: Permits to divide the first 2 nodes and store to 2nd node.
 */
void div(stack_t **stack, int line_number)
{
stack_t *tmp;

if ((*stack) == NULL || (*stack)->next == NULL)
{
printf("L%d: can't div, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
if ((*stack)->n == 0)
{
printf("L%d: division by zero\n", line_number);
exit(EXIT_FAILURE);
}

tmp = (*stack)->next;
tmp->n = tmp->n / (*stack)->n;
pop(stack, line_number);
}
