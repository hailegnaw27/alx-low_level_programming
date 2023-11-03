#include "hash_tables.h"

/**
 * shash_table_t - Sorted hash table data structure
 */
typedef struct shash_table_s
{
	hash_table_t *sht;
	hash_node_t **shead;
	hash_node_t **stail;
} shash_table_t;

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the hash table
 * Return: A pointer to the new hash table or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *sht = malloc(sizeof(shash_table_t));

	if (sht == NULL)
		return (NULL);

	sht->sht = hash_table_create(size);
	if (sht->sht == NULL)
	{
		free(sht);
		return (NULL);
	}

	sht->shead = NULL;
	sht->stail = NULL;

	return (sht);
}

/**
 * shash_table_set - Adds or updates an element in the sorted hash table
 * @ht: The sorted hash table
 * @key: The key of the element
 * @value: The value of the element
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	hash_table_t *sht;
	hash_node_t *node, *prev = NULL;
	unsigned long int index;

	if (ht == NULL || key == NULL || strlen(key) == 0 || value == NULL)
		return (0);

	sht = ht->sht;
	index = key_index((const unsigned char *)key, sht->size);
	node = sht->array[index];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
		{
			free(node->value);
			node->value = strdup(value);
			if (node->value == NULL)
				return (0);
			return (1);
		}
		if (strcmp(node->key, key) > 0)
			break;
		prev = node;
		node = node->next;
	}

	node = create_node(key, value);
	if (node == NULL)
		return (0);

	if (prev == NULL)
	{
		if (sht->array[index] == NULL)
			ht->shead = &node;
		node->next = sht->array[index];
		sht->array[index] = node;
	}
	else
	{
		if (prev->next == NULL)
			ht->stail = &node;
		node->next = prev->next;
		prev->next = node;
	}

	return (1);
}

/**
 * shash_table_get - Retrieves an element from the sorted hash table
 * @ht: The sorted hash table
 * @key: The key of the element
 * Return: The value of the element or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	hash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || strlen(key) == 0)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->sht->size);
	node = ht->sht->array[index];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table
 * @ht: The sorted hash table to print
 */
void shash_table_print(const shash_table_t *ht)
{
	hash_node_t *node;
	int flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (node = *(ht->shead); node != NULL; node = node->next)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		flag = 1;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order
 * @ht: The sorted hash table to print
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	hash_node_t *node;
	int flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (node = *(ht->stail); node != NULL; node = node->prev)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		flag = 1;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The sorted hash table to delete
 */
void shash_table_delete(shash_table_t *ht)
{
	if (ht == NULL)
		return;

	hash_table_delete(ht->sht);
	free(ht);
}

/**
 * create_node - Creates a hash node with key/value pairs
 * @key: The key of the node
 * @value: The value of the node
 * Return: A pointer to the new node or NULL on failure
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *node = malloc(sizeof(hash_node_t));

	if (node == NULL || key == NULL || strlen(key) == 0 ||
		value == NULL || strcmp(key, "") == 0)
	{
		free(node);
		return (NULL);
	}

	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	}

	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	node->prev = NULL;

	return (node);
}
