#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - Searches a string for any of a set of bytes
 * @s: The string to search
 * @accept: The characters to search for
 *
 * Return: Pointer to the first occurrence of any character from accept in s,
 *         or NULL if no such character is found
 */
char *_strpbrk(char *s, char *accept)
{
	while (*s != '\0')
	{
		char *a = accept;
		while (*a != '\0')
		{
			if (*a == *s)
				return s;
			a++;
		}
		s++;
	}

	return NULL;
}

