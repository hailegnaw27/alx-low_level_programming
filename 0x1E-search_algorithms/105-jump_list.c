#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted list of integers using
 *             the Jump search algorithm
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located,
 *         or NULL if value is not present or if head is NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
    size_t jump, prev;
    listint_t *curr;

    if (list == NULL || size == 0)
        return NULL;

    jump = sqrt(size);
    prev = 0;
    curr = list;

    while (curr->index < size && curr->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
        prev = curr->index;
        for (size_t i = 0; curr->next && i < jump; i++)
            curr = curr->next;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev, curr->index);

    while (prev <= curr->index && curr->n <= value)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev, curr->n);
        if (curr->n == value)
            return curr;
        prev++;
        curr = curr->next;
    }

    return NULL;
}
