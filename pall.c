#include "monty.h"
/**
 * pall - Print all
 * @stack: The stack to be printed
 * Description: Print completely a stack
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
