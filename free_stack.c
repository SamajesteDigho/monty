#include "monty.h"
/**
 * free_stack - free stack
 * @stack: Stack concerned
 * Description: Free stack
 */
void free_stack(stack_t **stack)
{
while (*stack != NULL)
{
pop(stack, 0);
}
}
