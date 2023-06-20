#include "main.h"

/**
* print_last_digit - Prints the last digit of a number
* @n: The number whose last digit is to be printed
*
* Return: The value of the last digit
*/
int print_last_digit(int n)
{
int last_digit;
if (n < 10)
n = -n;
last_digit = n % 10;
_putcha(last_digit + '0');
return (last_digit);
}

