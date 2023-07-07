#include "main.h"

/**
 * _isalpha - Checks if a character is an alphabetic letter
 * @c: The character to check
 *
 * Return: 1 if the character is an alphabetic letter, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

