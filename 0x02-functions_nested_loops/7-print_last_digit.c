#include "main.h"
#include <limits.h>

/**
* print_last_digit - Prints the last digit of a number
* @n: The number whose last digit is to be printed
*
* Return: The value of the last digit
*/
int print_last_digit(int n)
{
int last_digit;

if (n == INT_MIN)
last_digit = 8;
else if (n < 0)
last_digit = -n % 10;
else
last_digit = n % 10;

_putchar(last_digit + '0');

return (last_digit);
}
