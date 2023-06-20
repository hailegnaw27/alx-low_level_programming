#include "main.h"

/**
* print_last_digit - Prints the last digit of a number
* @n: The number whose last digit is to be printed
*
* Return: The value of the last digit
*/
int print_last_digit(int n)
{
int last_digit = n % 10;
char c = last_digit + '0';
_putchar(c);
return (last_digit);
}

