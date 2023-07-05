#include "main.h"
#include <stdio.h>
#include <stdbool.h>

/**
 * is_palindrome - Checks if a string is a palindrome
 * @s: The string to check
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
    if (s == NULL)
        return (0);

    int len = get_length(s);
    return (check_palindrome(s, 0, len - 1));
}

/**
 * get_length - Calculates the length of a string recursively
 * @s: The string
 *
 * Return: The length of the string
 */
int get_length(char *s)
{
    if (*s == '\0')
        return (0);
    return (1 + get_length(s + 1));
}

/**
 * check_palindrome - Recursive helper function to check if a string is a palindrome
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

