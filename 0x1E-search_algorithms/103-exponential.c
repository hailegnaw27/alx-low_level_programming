#include <stdio.h>
#include "search_algos.h"

/**
 * exponential_search - Searches for a value in a sorted array using
 *                      exponential search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found or array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1;
    size_t prev = 0;
    size_t low, high;

    if (array == NULL || size == 0)
        return -1;

    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        prev = bound;
        bound *= 2;
    }

    if (bound >= size)
    {
        printf("Value found between indexes [%lu] and [%lu]\n", prev, bound - 1);
        low = prev;
        high = size - 1;
    }
    else
    {
        printf("Value found between indexes [%lu] and [%lu]\n", prev, bound);
        low = prev;
        high = bound;
    }

    while (low <= high)
    {
        size_t mid = (low + high) / 2;

        printf("Searching in array: ");
        for (size_t i = low; i <= high; i++)
        {
            if (i == high)
                printf("%d\n", array[i]);
            else
                printf("%d, ", array[i]);
        }

        if (array[mid] == value)
            return mid;

        if (array[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}
