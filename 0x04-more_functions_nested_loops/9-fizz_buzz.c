#include "main.h"

/**
* print_fizz_buzz - prints FizzBuzz for multiples of 3 and 5
* @i: current number
*
* Return: void
*/
void print_fizz_buzz(int i)
{
if (i % 3 == 0 && i % 5 == 0)
printf("FizzBuzz");
else if (i % 3 == 0)
printf("Fizz");
else if (i % 5 == 0)
printf("Buzz");
else
printf("%d", i);
}

/**
* fizz_buzz - prints numbers from 1 to 100, replacing multiples of 3 with Fizz,
* multiples of 5 with Buzz, and multiples of both with FizzBuzz
*
* Return: void
*/
void fizz_buzz(void)
{
int i;

for (i = 1; i <= 100; i++)
{
print_fizz_buzz(i);
if (i != 100)
printf(" ");
}
printf("\n");
}

