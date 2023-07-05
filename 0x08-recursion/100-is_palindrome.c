/**
 * is_palindrome - checks if a string is a palindrome
 * @s: the string to check
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
    int len = 0;

    if (*s == '\0')
        return (1);

    while (s[len] != '\0')
        len++;

    return (check_palindrome(s, 0, len - 1));
}

/**
 * check_palindrome - checks if a string is a palindrome recursively
 * @s: the string to check
 * @start: the starting index
 * @end: the ending index
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

