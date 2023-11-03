#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the hash table array
 *
 * Return: A pointer to the created hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht = malloc(sizeof(shash_table_t));
    unsigned long int i;

    if (ht == NULL)
        return (NULL);

    ht->size = size;
    ht->array = malloc(sizeof(shash_node_t *) * size);
    ht->shead = NULL;
    ht->stail = NULL;

    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }

    for (i = 0; i < size; i++)
        ht->array[i] = NULL;

    return (ht);
}

/**
 * shash_table_set - Inserts a key/value pair into a sorted hash table
 * @ht: The sorted hash table
 * @key: The key string
 * @value: The value string
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    shash_node_t *new_node, *tmp;
    unsigned long int index;

    if (ht == NULL || key == NULL || value == NULL)
        return (0);

    index = key_index((const unsigned char *)key, ht->size);
    tmp = ht->array[index];

    while (tmp != NULL)
    {
        if (strcmp(tmp->key, key) == 0)
        {
            free(tmp->value);
            tmp->value = strdup(value);
            return (1);
        }
        tmp = tmp->next;
    }

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = ht->array[index];
    new_node->sprev = NULL;
    new_node->snext = NULL;
    ht->array[index] = new_node;

    if (ht->shead == NULL)
    {
        ht->shead = new_node;
        ht->stail = new_node;
    }
    else if (strcmp(key, ht->shead->key) < 0)
    {
        new_node->snext = ht->shead;
        ht->shead->sprev = new_node;
        ht->shead = new_node;
    }
    else
    {
        tmp = ht->shead;
        while (tmp->snext != NULL && strcmp(key, tmp->snext->key) > 0)
            tmp = tmp->snext;

        new_node->snext = tmp->snext;
        if (tmp->snext != NULL)
            tmp->snext->sprev = new_node;
        else
            ht->stail = new_node;
        new_node->sprev = tmp;
        tmp->snext = new_node;
    }

    return (1);
}

/**
 * shash_table_get - Retrieves the value associated with a key in a sorted hash table
 * @ht: The sorted hash table
 * @key: The key string
 *
 * Return: The value associated with the key, or NULL if key is not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    shash_node_t *tmp;
    unsigned long int index;

    if (ht == NULL || key == NULL)
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);
    tmp = ht->array[index];

    while (tmp != NULL)
    {
        if (strcmp(tmp->key, key) == 0)
            return (tmp->value);
        tmp = tmp->next;
    }

    return (NULL);
}

/**
 * shash_table_print - Prints the key/value pairs in a sorted hash table
 * @ht: The sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *tmp;
    int first = 1;

    if (ht == NULL)
        return;

    printf("{");
    tmp = ht->shead;
    while (tmp != NULL)
    {
        if (!first)
            printf(", ");
        printf("'%s': '%s'", tmp->key, tmp->value);
        first = 0;
        tmp = tmp->snext;
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Prints the key/value pairs in reverse order in a sorted hash table
 * @ht: The sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *tmp;
    int first = 1;

    if (ht == NULL)
        return;

    printf("{");
    tmp = ht->stail;
    while (tmp != NULL)
    {
        if (!first)
            printf(", ");
        printf("'%s': '%s'", tmp->key, tmp->value);
        first = 0;
        tmp = tmp->sprev;
    }
    printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *tmp, *next;
    unsigned long int i;

    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        tmp = ht->array[i];
        while (tmp != NULL)
        {
            next = tmp->next;
            free(tmp->key);
            free(tmp->value);
            free(tmp);
            tmp = next;
        }
    }

    free(ht->array);
    free(ht);
}

