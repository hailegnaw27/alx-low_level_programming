#include "main.h"
#include <stdio.h>
/**
* print_times_table - Prints the n times table, starting with 0
* @n: The number of times to print the times table
*/
void print_times_table(int n)
{
int i, j, result;

if (n >= 0 && n <= 15)
{
for (i = 0; i <= n; i++)
{
for (j = 0; j <= n; j++)
{
result = i * j;

if (j == 0)
{
printf("%d", result);
}
else if (result < 10)
{
printf("   %d", result);
}
else if (result < 100)
{
printf("  %d", result);
}
else
{
printf(" %d", result);
}

if (j != n)
{
printf(",");
}
}

printf("\n");
}
}
}
