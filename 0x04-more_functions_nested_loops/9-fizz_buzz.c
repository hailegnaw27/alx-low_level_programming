#include "main.h"
#include <stdio.h>

/**
* fizz_buzz - prints the numbers from 1 to 100,  multiples of 3 with "Fizz",
* multiples of 5 with "Buzz", and multiples of both 3 and 5 with "FizzBuzz"
*/
void fizz_buzz(void)
{
int i;

for (i = 1; i <= 100; i++)
{
if (i % 3 == 0 && i % 5 == 0)
printf("FizzBuzz ");
else if (i % 3 == 0)
printf("Fizz ");
else if (i % 5 == 0)
printf("Buzz ");
else
printf("%d ", i);
}
printf("\n");
}
