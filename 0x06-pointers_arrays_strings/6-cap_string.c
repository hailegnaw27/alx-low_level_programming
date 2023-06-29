#include "main.h"

/**
* cap_string - Capitalizes all words of a string
* @str: The string to capitalize
*
* Return: The capitalized string
*/
char *cap_string(char *str)
{
int i = 0;
bool new_word = true;
char separators[] = " \t\n,;.!?\"(){}";

while (str[i] != '\0')
{
if (new_word && (str[i] >= 'a' && str[i] <= 'z'))
{
str[i] = str[i] - 32;
}

new_word = false;

for (int j = 0; separators[j] != '\0'; j++)
{
if (str[i] == separators[j])
{
new_word = true;
break;
}
}

i++;
}

return (str);
}
