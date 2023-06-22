#include <stdio.h>

/**
* main - finds and prints the largest prime factor of 612852475143
*
* Return: always 0
*/
int main(void)
{
long int n = 612852475143;
long int i;

for (i = 2; i <= n; i++)
{
while (n % i == 0)
{
n /= i;
}
}

printf("%ld\n", i - 1);

return (0);
}
