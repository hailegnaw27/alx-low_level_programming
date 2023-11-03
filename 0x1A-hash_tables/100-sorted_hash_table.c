#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created hash table, or NULL if it fails
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;
    unsigned long int i;

    if (size == 0)
        return (NULL);

    ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return (NULL);

    ht->size = size;
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }

    for (i = 0; i < size; i++)
        ht->array[i] = NULL;

    ht->shead = NULL;
    ht->stail = NULL;

    return (ht);
}

/**
 * shash_table_set - Adds an element to the sorted hash table
 * @ht: The hash table to add or update the key/value to
 * @key: The key string
 * @value: The value corresponding to the key
 *
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    shash_node_t *new_node, *temp;
    unsigned long int index;

    if (ht == NULL || key == NULL || value == NULL)
        return (0);

    index = key_index((const unsigned char *)key, ht->size);

    temp = ht->array[index];
    while (temp != NULL)
    {
        if (strcmp(temp->key, key) == 0)
        {
            free(temp->value);
            temp->value = strdup(value);
            return (1);
        }
        temp = temp->next;
    }

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    if (ht->shead == NULL)
    {
        new_node->sprev = NULL;
        new_node->snext = NULL;
        ht->shead = new_node;
        ht->stail = new_node;
    }
    else
    {
        temp = ht->shead;
        while (temp != NULL && strcmp(key, temp->key) > 0)
            temp = temp->snext;

        if (temp == NULL)
        {
            new_node->sprev = ht->stail;
            new_node->snext = NULL;
            ht->stail->snext = new_node;
            ht->stail = new_node;
        }
        else if (temp == ht->shead)
        {
            new_node->sprev = NULL;
            new_node->snext = ht->shead;
            ht->shead->sprev = new_node;
            ht->shead = new_node;
        }
        else
        {
            new_node->sprev = temp->sprev;
            new_node->snext = temp;
            temp->sprev->snext = new_node;
            temp->sprev = new_node;
        }
    }

    return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key from the hash table
 * @ht: The hash table to look into
 * @key: The key string
 *
 * Return: The value associated with the key, or NULL if key couldn't be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    shash_node_t *temp;
    unsigned long int index;

    if (ht == NULL || key == NULL)
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);

    temp = ht->array[index];
    while (temp != NULL)
    {
        if (strcmp(temp->key, key) == 0)
            return (temp->value);
        temp = temp->next;
    }

    return (NULL);
}

/**
 * shash_table_print - Prints the sorted hash table
 * @ht: The hash table to print
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *temp;
    int flag = 0;
    unsigned long int i;

    if (ht == NULL)
        return;

    printf("{");
    for (i = 0; i < ht->size; i++)
    {
        temp = ht->array[i];
        while (temp != NULL)
        {
            if (flag == 1)
                printf(", ");
            printf("'%s': '%s'", temp->key, temp->value);
            flag = 1;
            temp = temp->next;
        }
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Prints the sorted hash table in reverse order
 * @ht: The hash table to print
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *temp;
    int flag = 0;

    if (ht == NULL)
        return;

    printf("{");
    temp = ht->stail;
    while (temp != NULL)
    {
        if (flag == 1)
            printf(", ");
        printf("'%s': '%s'", temp->key, temp->value);
        flag = 1;
        temp = temp->sprev;
    }
    printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The hash table to delete
 */
void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *temp, *prev;
    unsigned long int i;

    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        temp = ht->array[i];
        while (temp != NULL)
        {
            prev = temp;
            temp = temp->next;
            free(prev->key);
            free(prev->value);
            free(prev);
        }
    }

    free(ht->array);
    free(ht);
}

