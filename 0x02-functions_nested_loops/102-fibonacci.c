#include "main.h"
#include <stdio.h>

/**
* main - Prints the first 50 Fibonacci numbers
*
* Return: Always 0
*/
int main(void)
{
int i;
long int a, b, c;

a = 1;
b = 2;

printf("%ld, %ld", a, b);

for (i = 3; i <= 50; i++)
{
c = a + b;
printf(", %ld", c);
a = b;
b = c;
}

printf("\n");

return (0);
}
