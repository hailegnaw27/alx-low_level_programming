#include "main.h"
/**
* largest_number - finds the largest number among three integers
*
* @a: first integer
* @b: second integer
* @c: third integer
*
* Return: the largest number
*/
int largest_number(int a, int b, int c)
{
int largest;

if (a >= b && a >= c)
{
largest = a;
}
else if (b >= a && b >= c)
{
largest = b;
}
else
{
largest = c;
}

return (largest);
}
