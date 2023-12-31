/**
* _strcmp - Compares two strings
* @s1: First string
* @s2: Second string
*
* Return: Difference between the ASCII values of the first differing characters
*         0 if strings are equal
*/
int _strcmp(char *s1, char *s2)
{
int i;

for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
{
if (s1[i] != s2[i])
return (s1[i] - s2[i]);
}

return (0);
}
