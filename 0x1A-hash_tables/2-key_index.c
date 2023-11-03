#include "hash_tables.h"

/**
 * key_index - Gives the index of a key in a hash table array
 * @key: The key to get the index for
 * @size: The size of the hash table array
 *
 * Return: The index at which the key/value pair should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
unsigned long int hash;
hash = hash_djb2(key);
return (hash % size);
}

