#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - Prints a hash table
 * @ht: The hash table to print
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i, flag = 0;
	hash_node_t *temp_node = NULL;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		temp_node = ht->array[i];
		while (temp_node != NULL)
		{
			if (flag == 1)
				printf(", ");
			printf("'%s': '%s'", temp_node->key, temp_node->value);
			flag = 1;
			temp_node = temp_node->next;
		}
	}
	printf("}\n");
}
