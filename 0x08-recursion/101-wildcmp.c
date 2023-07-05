#include "main.h"
#include <stdio.h>

/**
* wildcmp - Compares two strings and checks if they can be considered identical
* @s1: First string
* @s2: Second string
*
* Return: 1 if the strings can be considered identical, 0 otherwise
*/
int wildcmp(char *s1, char *s2)
{
if (*s2 == '*')
{
if (*(s2 + 1) == '\0')
return (1);
if (*s1 != '\0' && wildcmp(s1 + 1, s2))
return (1);
return (wildcmp(s1, s2 + 1));
}
if (*s1 == *s2)
{
if (*s1 == '\0')
return (1);
return (wildcmp(s1 + 1, s2 + 1));
}
return (0);
}
