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
 * is_numeric - Is numeric
 * @buffer: In which the trimed line is stored
 * Description: Check if string is essentially numeric
 * Return: 1 for success -1 otherwise
 */
int is_numeric(char *buffer)
{
size_t i;
trim_line(buffer, buffer);
for (i = 0; i < strlen(buffer); i++)
{
if ((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '-')
{
return (-1);
}
}
return (1);
}
