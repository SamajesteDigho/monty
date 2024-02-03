#include "monty.h"
/**
 * rotr - Reverse stack
 * @stack: Stack concerned
 * @line_number: Line number in monty file
 * Description: Reverses a stack
 * Return: Always 0
 */
int rotr(stack_t **stack)
{
stack_t *tmp, *cur;
cur = *stack;
if (cur == NULL || cur->next == NULL)
{
return (0);
}
while (cur != NULL)
{
tmp = cur;
cur = cur->next;
tmp->next = tmp->prev;
tmp->prev = tmp->next;
}
tmp->prev = NULL;
*stack = tmp;
return (0);
}
