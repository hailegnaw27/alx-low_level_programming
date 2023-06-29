/**
* _strcat - concatenates two strings
* @dest: the destination string
* @src: the source string
*
* Return: a pointer to the resulting string `dest`
*/
char *_strcat(char *dest, char *src)
{
int i = 0;
int j = 0;

/* Find the end of the destination string */
while (dest[i] != '\0')
{
i++;
}

/* Concatenate the source string to the destination string */
while (src[j] != '\0')
{
dest[i] = src[j];
i++;
j++;
}

/* Add the null terminator at the end */
dest[i] = '\0';

return (dest);
}
