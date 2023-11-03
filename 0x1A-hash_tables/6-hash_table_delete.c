#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table
 * @ht: The hash table to delete
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *temp_node = NULL, *prev_node = NULL;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		temp_node = ht->array[i];
		while (temp_node != NULL)
		{
			prev_node = temp_node;
			temp_node = temp_node->next;
			free(prev_node->key);
			free(prev_node->value);
			free(prev_node);
		}
	}
	free(ht->array);
	free(ht);
}
