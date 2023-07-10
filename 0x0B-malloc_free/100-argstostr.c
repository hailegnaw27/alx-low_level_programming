#include <stdlib.h>
#include "main.h"
/**
* argstostr - Concatenates all the arguments of a program
* @ac: The number of arguments
* @av: The array of arguments
*
* Return: A pointer to the concatenated string, or NULL if it fails
*/
char *argstostr(int ac, char **av)
{
int i, j, len = 0, index = 0;
char *str;

if (ac == 0 || av == NULL)
return (NULL);

for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j]; j++)
len++;
len++;  /* Account for the '\n' character */
}

str = malloc(sizeof(char) * (len + 1));
if (str == NULL)
return (NULL);

for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j]; j++)
{
str[index] = av[i][j];
index++;
}
str[index] = '\n';
index++;
}
str[index] = '\0';

return (str);
}
