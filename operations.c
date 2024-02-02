#include "monty.h"
/**
 * trim_line - Remove spaces
 * @buffer: In which the trimed line is stored
 * @line: The line to be trimed
 * Description: Permits to removing trailing spaces in a line (string)
 * Return: 1 for success -1 otherwise
 */
int trim_line(char *buffer, char *line)
{
char c;
int cur = 0, i = 0, start = 0, nbelt = 0;
if (line == NULL)
{
return (-1);
}
c = line[cur];
while (c != '\0' && c != '\n')
{
if (c != ' ')
{
if (start == 2)
{
buffer[i] = ' ';
i++;
}
buffer[i] = c;
start = 1;
i++;
}
else if (start == 1 && c == ' ')
{
if (nbelt == 1)
{
break;
}
start = 2;
nbelt = 1;
}
cur++;
c = line[cur];
}
buffer[i] = '\0';
return (0);
}

/**
 * valid_operation - Validate operation
 * @operation: The operation to validate
 * Description: Gets a line and determine if the operation is a valid one
 * Return: The int code of the operation
 */
int valid_operation(char *operation)
{
if (strncmp("push", operation, OP_SIZE) == 0)
{
return (1);
}
else if (strncmp("pall", operation, OP_SIZE) == 0)
{
return (2);
}
else if (strncmp("pint", operation, OP_SIZE) == 0)
{
return (3);
}
else if (strncmp("pop", operation, 3) == 0)
{
return (4);
}
else if (strncmp("swap", operation, OP_SIZE) == 0)
{
return (5);
}
else if (strncmp("add", operation, 3) == 0)
{
return (6);
}
else if (strncmp("nop", operation, 3) == 0)
{
return (7);
}
return (-1);
}

/**
 * get_value - Collect a value
 * @command: The command line
 * @cmd_len: The length of the search commande
 * Description: Permits to extract the value from a given command
 * Return: The value of the command
 */
int get_value(char *command, int cmd_len)
{
size_t i, j = 0;
char buffer[10];
for (i = cmd_len; i < strlen(command); i++)
{
buffer[j] = command[i];
j++;
}
buffer[j] = '\0';
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
type = valid_operation(operation);
if (type == 1)
{
val = get_value(operation, 4);
if (val == -1)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
push(stack, val);
}
else if (type == 2)
pall(*stack);
else if (type == 3)
{
pint(*stack, line_number);
}
else if (type == 4)
{
pop(stack, line_number);
}
else if (type == 5)
{
swap(stack, line_number);
}
else if (type == 6)
{
add(stack, line_number);
}
else if (type == 7)
{
printf("Does nothing\n");
}
else
{
printf("Unknown commnd found\n");
exit(EXIT_FAILURE);
}
return (1);
}
