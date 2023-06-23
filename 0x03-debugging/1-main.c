#include <stdio.h>

/**
* main - causes an infinite loop
* Return: 0
*\\o/\n - Print a message indicating Infinite loop avoided
* int i; - Counter variable for the loop
*/

int main(void)
{
int i;

printf("Infinite loop incoming :(\n");
i = 0;
/**
*This loop will cause an infinite loop
* while (i < 10)
*{
*        putchar(i);
*}
*/
printf("Infinite loop avoided! \\o/\n");

return (0);
}
