#include "main.h"

/**
 * _puts_recursion - Prints a string, followed by a new line
 * @s: The string to be printed
 */
void _puts_recursion(char *s)
{
    if (*s == '\0') /* base case: end of string */
    {
        _putchar('\n'); /* print new line */
        return;
    }
    
    _putchar(*s); /* print current character */
    _puts_recursion(s + 1); /* call the function recursively for the next character */
}

