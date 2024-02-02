#include "monty.h"
/**
 * pchar - Print first char
 * @stack: Stack concerned
 * @line_number: Line number in monty file
 * Description: Prints the first element of a stack as character if not empty
 */
void pchar(stack_t *stack, int line_number)
{

if (stack == NULL)
{
printf("L%d: can't pchar, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
if (stack->n < 0 || stack->n > 127)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
exit(EXIT_FAILURE);
}
printf("%c\n", stack->n);
}
