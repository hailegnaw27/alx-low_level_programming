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
printf(", %lu", next_num);
j = k;
k = next_num;
}
printf("\n");
return (0);
}
