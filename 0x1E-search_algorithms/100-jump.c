#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array using jump search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found or array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
    size_t step = sqrt(size);
    size_t prev = 0;

    if (array == NULL || size == 0)
        return -1;

    while (array[prev] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);

        if (prev + step >= size)
            break;

        prev += step;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev - step, prev);

    while (array[prev] >= value)
    {
        printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);

        if (array[prev] == value)
            return prev;

        if (prev == 0)
            break;

        prev--;
    }

    return -1;
}
