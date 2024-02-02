#include "monty.h"
/**
 * get_operation_string - Validate operation
 * @buffer: The buffer to put the string in.
 * @operation: The operation to validate
 * Description: Gets operation string
 * Return: the size of the string
 */
int get_operation_string(char *buffer, char *operation)
{
size_t i;
for (i = 0; i < strlen(operation); i++)
{
if (operation[i] == ' ')
{
break;
}
buffer[i] = operation[i];
}
buffer[i] = '\0';
return (i);
}

/**
 * valid_operation - Validate operation
 * @operation: The operation to validate
 * Description: Gets a line and determine if the operation is a valid one
 * Return: The int code of the operation
 */
int valid_operation(char *operation)
{
if (strlen(operation) == 0)
return (0);
if (strncmp("#", operation, 1) == 0)
return (0);
else if (strcmp("nop", operation) == 0)
return (0);
else if (strcmp("push", operation) == 0)
return (1);
else if (strcmp("pall", operation) == 0)
return (2);
else if (strcmp("pint", operation) == 0)
return (3);
else if (strcmp("pop", operation) == 0)
return (4);
else if (strcmp("swap", operation) == 0)
return (5);
else if (strcmp("add", operation) == 0)
return (6);
else if (strcmp("sub", operation) == 0)
return (7);
else if (strcmp("div", operation) == 0)
return (8);
else if (strcmp("mul", operation) == 0)
return (9);
else if (strcmp("mod", operation) == 0)
return (10);
else if (strcmp("pchar", operation) == 0)
return (11);
return (-1);
}

/**
 * get_value - Collect a value
 * @command: The command line
 * @cmd_len: The length of the search commande
 * @line_number: Line number
 * Description: Permits to extract the value from a given command
 * Return: The value of the command
 */
int get_value(char *command, int cmd_len, int line_number)
{
size_t i, j = 0;
char buffer[10];
for (i = cmd_len; i < strlen(command); i++)
{
buffer[j] = command[i];
j++;
}
buffer[j] = '\0';
if (strlen(buffer) == 0 || is_numeric(buffer) == -1)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
return (atoi(buffer));
}

/**
 * execute_operation - Executes operation
 * @stack: the stack to study
 * @operation: The operation to execute
 * @line_number: The line number of the instruction to execute
 * Description: Thi function permits to call the different command functions
 * Return: 1 or EXIT_FAILURE otherwise
 */
int execute_operation(stack_t **stack, char *operation, int line_number)
{
int type, val;
char buffer[10];
get_operation_string(buffer, operation);
type = valid_operation(buffer);
if (type == 1)
{
val = get_value(operation, 4, line_number);
push(stack, val);
}
else if (type == 2)
pall(*stack);
else if (type == 3)
pint(*stack, line_number);
else if (type == 4)
pop(stack, line_number);
else if (type == 5)
swap(stack, line_number);
else if (type == 6)
add(stack, line_number);
else if (type == 7)
sub(stack, line_number);
else if (type == 8)
_div(stack, line_number);
else if (type == 9)
mul(stack, line_number);
else if (type == 10)
mod(stack, line_number);
else if (type == 11)
pchar(*stack, line_number);
else if (type == 0)
return (1);
else
{
fprintf(stderr, "Unknown commnd found\n");
exit(EXIT_FAILURE);
}
return (1);
}
