#include "main.h"
#include <stdio.h>
/**
* main - Entry point
* Return: Always 0 (Success)
*/
int main(void)
{
int i;
unsigned long int j = 1, k = 2, next_num;

printf("%lu, %lu", j, k);
for (i = 0; i < 96; i++)
{
next_num = j + k;
if (i % 10 == 8)
printf("%lu,\n", next_num);
if (i == 95)
printf(", %lu\n", next_num);
else
printf(", %lu", next_num);
j = k;
k = next_num;
}
return (0);
}
