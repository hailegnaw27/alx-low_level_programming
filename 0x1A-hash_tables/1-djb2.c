/**
 * hash_djb2 - Hash function using djb2 algorithm
 * @str: String to hash
 *
 * Return: Hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash = 5381;
	int c;

	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}

	return (hash);
}
