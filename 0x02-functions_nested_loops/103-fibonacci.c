#include "main.h"

/**
* fibonacci - Generates the Fibonacci sequence
* @n: The maximum value of the sequence
*
* Return: A pointer to the head of the sequence
*/
int *fibonacci(int n)
{
static int sequence[100];
int i;

sequence[0] = 1;
sequence[1] = 2;

for (i = 2; i < 100; i++)
{
sequence[i] = sequence[i - 1] + sequence[i - 2];
if (sequence[i] > n)
break;
}

return (sequence);
}

/**
* main - Entry point
*
* Return: Always 0
*/
int main(void)
{
int *seq, i, sum;

seq = fibonacci(4000000);
sum = 0;

for (i = 0; seq[i] != 0; i++)
{
if (seq[i] % 2 == 0)
sum += seq[i];
}

_putchar(sum / 10 + '0');
_putchar(sum % 10 + '0');
_putchar('\n');

return (0);
}
