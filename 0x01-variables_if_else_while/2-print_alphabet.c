#include <stdio.h>
/**
* main - Entry point
*
* Return: Always 0 (Success)
*/
int main() {
char letter = 'a';
do 
{
putchar(letter);
letter++;
}
while (letter <= 'z');
putchar('\n');
return 0;
}
