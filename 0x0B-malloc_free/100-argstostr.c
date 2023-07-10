#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* argstostr - concatenates all the arguments of the program
* @ac: argument count
* @av: argument vector
*
* Return: pointer to the concatenated string
*/
char *argstostr(int ac, char **av)
{
char *str;
int i, j, k, len;
int total_len = 0;

if (ac == 0 || av == NULL)
return (NULL);

for (i = 0; i < ac; i++)
{
len = 0;
while (av[i][len] != '\0')
{
len++;
}
total_len += len + 1;
}

str = malloc(sizeof(char) * total_len);
if (str == NULL)
return (NULL);

k = 0;
for (i = 0; i < ac; i++)
{
len = 0;
while (av[i][len] != '\0')
{
str[k] = av[i][len];
len++;
k++;
}
str[k] = '\n';
k++;
}

return (str);
}
