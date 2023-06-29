/**
* leet - Encodes a string into 1337
* @str: The string to be encoded
*
* Return: The encoded string
*/
char *leet(char *str)
{
int i, j;
char leet_letters[] = "aAeEoOtTlL";
char leet_numbers[] = "4433007711";

for (i = 0; str[i] != '\0'; i++)
{
for (j = 0; j < 10; j++)
{
if (str[i] == leet_letters[j])
str[i] = leet_numbers[j];
}
}

return (str);
}

