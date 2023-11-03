/**
 * key_index - Computes the index of a key in a hash table
 * @key: Key string
 * @size: Size of the hash table
 *
 * Return: Index of the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value = hash_djb2(key);

	return (hash_value % size);
}
