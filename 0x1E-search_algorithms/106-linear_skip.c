#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 *
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located,
 *         or NULL if value is not present or if head is NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *express, *prev;

    if (list == NULL)
        return NULL;

    express = list->express;
    prev = list;

    while (express && express->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
        prev = express;
        express = express->express;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev->index, express ? express->index : prev->index);
    
    while (prev && prev->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
        prev = prev->next;
    }

    if (prev && prev->n == value)
        return prev;

    return NULL;
}
