#include "monty.h"
/**
 * pstr - Print string
 * @stack: Stack concerned
 * @line_number: Line number in monty file
 * Description: Prints the string out of a stack if not empty
 */
void pstr(stack_t *stack)
{
stack_t *tmp;
tmp = stack;
while (tmp != NULL)
{
if (tmp->n == 0 || tmp->n < 0 || tmp->n > 127)
{
break;
}
printf("%c", tmp->n);
tmp = tmp->next;
}
printf("\n");
}
