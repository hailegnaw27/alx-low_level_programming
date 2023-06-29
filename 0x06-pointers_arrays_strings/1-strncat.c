/**
* _strncat - concatenates two strings
* @dest: the destination string
* @src: the source string
* @n: the maximum number of characters to be concatenated from src
*
* Return: a pointer to the resulting string `dest`
*/
char *_strncat(char *dest, char *src, int n)
{
int i = 0;
int j = 0;

/* Find the end of the destination string */
while (dest[i] != '\0')
{
i++;
}

/* Concatenate the source string to the destination string */
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}

/* Add the null terminator at the end */
dest[i] = '\0';

return (dest);
}
