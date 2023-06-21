#include "main.h"
#include <stdio.h>

/**
* main - Entry point
*
* Description: Tests the positive_or_negative() function with a case of 0
*
* Return: Always 0 (Success)
*/

int main(void)
{
int zero = 0;

positive_or_negative(zero);

if (zero == 0)
{
printf("0 is zero\n");
}
else
{
printf("Test failed\n");
}

return (0);
}
