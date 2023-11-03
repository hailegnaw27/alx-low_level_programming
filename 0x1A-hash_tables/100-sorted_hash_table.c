#include "advanced.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the hash table
 * Return: A pointer to the new hash table or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *sht = malloc(sizeof(shash_table_t));

    if (!sht)
        return (NULL);

    sht->size = size;
    sht->shead = NULL;
    sht->stail = NULL;
    sht->array = calloc(size, sizeof(shash_node_t *));
    if (!sht->array)
    {
        free(sht);
        return (NULL);
    }

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
    unsigned long int index;
    shash_node_t *node, *prev;

    if (!ht || !key || !value || strcmp(key, "") == 0)
        return (0);
    index = key_index((const unsigned char *)key, ht->size);
    node = ht->array[index];
    prev = NULL;

    while (node)
    {
        if (strcmp(node->key, key) == 0)
        {
            free(node->value);
            node->value = strdup(value);
            if (!node->value)
                return (0);
            return (1);
        }
        if (strcmp(key, node->key) < 0)
            break;
        prev = node;
        node = node->next;
    }

    node = create_shash_node(key, value);
    if (!node)
        return (0);

    if (!prev)
        ht->array[index] = node;
    else
        prev->next = node;
    node->next = node_in_place(ht, node);

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
    shash_node_t *node;
    unsigned long int index;

    if (!ht || !key)
        return (NULL);

   index = key_index((const unsigned char *)key, ht->size);
    node = ht->array[index];

    while (node)
    {
        if (strcmp(node->key, key) == 0)
            return (node->value);
        if (strcmp(node->key, key) > 0)
            break;
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
    shash_node_t *node;
    int flag = 0;

    if (!ht)
        return;

    printf("{");
    for (node = ht->shead; node; node = node->snext)
    {
        if (flag)
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
    shash_node_t *node;
    int flag = 0;

    if (!ht)
        return;

    printf("{");
    for (node = ht->stail; node; node = node->sprev)
    {
        if (flag)
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
    unsigned long int i;
    shash_node_t *node, *tmp;

    if (!ht)
        return;

    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node)
        {
            tmp = node;
            node = node->next;
            free(tmp->key);
            free(tmp->value);
            free(tmp);
        }
    }

    free(ht->array);
    free(ht);
}

/**
 * create_shash_node - Creates a new shash_node_t with given key & value
 * @key: The key to use in the new node
 * @value: The value to use in the new node
 * Return: A pointer to the new node or NULL on failure
 */
shash_node_t *create_shash_node(const char *key, const char *value)
{
    shash_node_t *node;

    node = malloc(sizeof(shash_node_t));
    if (!node)
        return (NULL);

    node->key = strdup(key);
    if (!node->key)
    {
        free(node);
        return (NULL);
    }

    node->value = strdup(value);
    if (!node->value)
    {
        free(node->key);
        free(node);
        return (NULL);
    }

    node->next = NULL;

    return (node);
}

/**
 * node_in_place - Places a shash_node_t in its rightful sorted location
 * in a sorted hash table.
 * @ht: Pointer to the sorted hash table.
 * @node: Pointer to the shash_node_t to place.
 * Return: Pointer to the first node in the linked list.
 */
shash_node_t *node_in_place(shash_table_t *ht, shash_node_t *node)
{
    shash_node_t *list, *tmp;

    if (!ht->shead)
    {
        ht->shead = ht->stail = node;
        node->sprev = node->snext = NULL;
        return (node);
    }

    list = ht->shead;
    while (list)
    {
        if (strcmp(node->key, list->key) < 0)
        {
            tmp = list->sprev;
            list->sprev = node;
            node->sprev = tmp;
            if (tmp)
                tmp->snext = node;
            else
                ht->shead = node;
            node->snext = list;
            return (ht->shead);
        }
        list = list->snext;
    }

    node->sprev = ht->stail;
    node->snext = NULL;
    ht->stail->snext = node;
    ht->stail = node;
    return (ht->shead);
}
