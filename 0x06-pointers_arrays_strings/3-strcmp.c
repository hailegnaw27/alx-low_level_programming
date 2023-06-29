**
* _strcmp - compares two strings
* @s1: first string
* @s2: second string
*
* Return: negative if s1 is less than s2, positive if s1 is greater than s2,
*         and 0 if s1 is equal to s2
*/
int _strcmp(char *s1, char *s2)
{
int i = 0;

while (s1[i] == s2[i])
{
if (s1[i] == '\0')
return 0;
i++;
}
