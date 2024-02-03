#include "monty.h"
/**
 * stack_queue - Swap stack to queue and vice versa
 * @stack: Stack concerned
 * @type: 1 for stack and 2 for queue
 * Description: Swap the first 2 elements of the stack if possible
 */
void stack_queue(stack_t **stack, int type)
{
if (type == 1)
stack = stack;
else
rotr(stack);
}
