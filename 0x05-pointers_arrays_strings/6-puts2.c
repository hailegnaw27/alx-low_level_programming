#include "main.h"

/**
 * puts2 - Prints every other character of a string, starting with the first
 * @str: Pointer to the string to be printed
 */
void puts2(char *str)
{
	int len = 0;

	/* Find the length of the string */
	while (str[len] != '\0')
	{
		len++;
	}

	/* Print every other character */
	for (int i = 0; i < len; i += 2)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}

