#include <stdlib.h>
#include <string.h>

/**
* count_words - Counts the number of words in a string
* @str: The input string
*
* Return: The number of words
*/
int count_words(char *str)
{
int count = 0, i;

for (i = 0; str[i] != '\0'; i++)
{
if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
count++;
}

return (count);
}

/**
* strtow - Splits a string into words
* @str: The input string
*
* Return: A pointer to an array of strings (words), or NULL if it fails
*/
char **strtow(char *str)
{
int i, j, k, len, count = 0;
char **words;

if (str == NULL || str[0] == '\0')
return (NULL);

count = count_words(str);
if (count == 0)
return (NULL);

words = malloc(sizeof(char *) * (count + 1));
if (words == NULL)
return (NULL);

j = 0;
for (i = 0; str[i] != '\0' && j < count; i++)
{
if (str[i] != ' ')
{
len = 0;
k = i;
while (str[k] != ' ' && str[k] != '\0')
{
len++;
k++;
}

words[j] = malloc(sizeof(char) * (len + 1));
if (words[j] == NULL)
return (NULL);

strncpy(words[j], &str[i], len);
words[j][len] = '\0';
i += len - 1;
j++;
}
}
words[j] = NULL;

return (words);
}
