#include "main.h"
#include <stdio.h>

/**
* main - Prints the first 90 Fibonacci numbers
*
* Return: Always 0
*/
int main(void)
{
int i;
long int a = 0, b = 1, c;

for (i = 0; i < 90; i++)
{
if (i < 2)
c = i;
else
{
c = a + b;
a = b;
b = c;
}

printf("%ld", c);

if (i < 89)
printf(", ");
}

printf("\n");

return (0);
}
