#include "monty.h"
/**
 * rotl - Reverse stack
 * @stack: Stack concerned
 * @line_number: Line number in monty file
 * Description: Reverses a stack
 * Return: Always 0
 */
int rotl(stack_t **stack)
{
stack_t *tmp, *cur;
cur = *stack;
tmp = *stack;
if (cur == NULL || cur->next == NULL)
{
return(0);
}
while (tmp->next != NULL)
{
tmp = tmp->next;
}
(*stack) = cur->next;
(*stack)->prev = NULL;
cur->next = NULL;
cur->prev = tmp;
tmp->next = cur;
return (0);
}
