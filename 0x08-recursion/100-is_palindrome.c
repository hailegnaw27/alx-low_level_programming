#include "main.h"
#include <stdio.h>

/**
* is_palindrome - Checks if a string is a palindrome
* @s: The string to check
*
* Return: 1 if the string is a palindrome, 0 otherwise
*/
int is_palindrome(char *s)
{
int len = 0;

if (s == NULL)
return (0);

while (s[len] != '\0')
len++;

return (check_palindrome(s, 0, len - 1));
}

/**
* check_palindrome - Recursive helper function to
* check if a string is a palindrome
* @s: The string to check
* @start: The starting index
* @end: The ending index
*
* Return: 1 if the string is a palindrome, 0 otherwise
*/
int check_palindrome(char *s, int start, int end)
{
if (start >= end)
return (1);

if (s[start] != s[end])
return (0);

return (check_palindrome(s, start + 1, end - 1));
}
