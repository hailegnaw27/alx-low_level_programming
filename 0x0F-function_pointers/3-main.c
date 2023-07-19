#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
* main - Entry point
* @argc: Number of command-line arguments
* @argv: Array of command-line arguments
*
* Return: 0 on success, 98 on wrong number of arguments,
* 99 on invalid operator, 100 on division/modulo by zero
*/
int main(int argc, char *argv[])
{
int num1, num2, result;
char *operator;

if (argc != 4)
{
printf("Error\n");
return (98);
}

num1 = atoi(argv[1]);
operator = argv[2];
num2 = atoi(argv[3]);

if (num2 == 0 && (*operator == '/' || *operator == '%'))
{
printf("Error\n");
return (100);
}

if (get_op_func(operator) == NULL)
{
printf("Error\n");
return (99);
}

result = get_op_func(operator)(num1, num2);
printf("%d\n", result);

return (0);
}
