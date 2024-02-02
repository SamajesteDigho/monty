#include "monty.h"
/**
 * pint - Print first
 * @stack: Stack concerned
 * @line_number: Line number in monty file
 * Description: Prints the first element of a stack if not empty
 */
void pint(stack_t *stack, int line_number)
{

if (stack != NULL)
{
printf("%d\n", stack->n);
}
else
{
printf("L%d: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
}
