#include "main.h"

/**
* main - Entry point, prints the sum of the even-valued terms in the Fibonacci sequence that do not exceed 4,000,000
*
* Return: Always 0
*/
int main(void)
{
int first_term = 1, second_term = 2, next_term, sum = 2;

while (second_term <= 4000000) {
next_term = first_term + second_term;
first_term = second_term;
second_term = next_term;

if (second_term % 2 == 0) {
sum += second_term;
}
}

_putchar(sum / 1000000 + '0');
_putchar((sum / 100000) % 10 + '0');
_putchar((sum / 10000) % 10 + '0');
_putchar((sum / 1000) % 10 + '0');
_putchar((sum / 100) % 10 + '0');
_putchar((sum / 10) % 10 + '0');
_putchar(sum % 10 + '0');
_putchar('\n');

return (0);
}
