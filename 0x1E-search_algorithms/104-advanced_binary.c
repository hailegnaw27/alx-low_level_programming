#include <stdio.h>
#include "search_algos.h"

/**
* advanced_binary_recursive - Recursive helper function for advanced_binary
* @array: Pointer to the first element of the array to search in
* @low: Starting index of the array or subarray
* @high: Ending index of the array or subarray
* @value: Value to search for
*
* Return: Index where value is located, or -1 if not found
*/
int advanced_binary_recursive(int *array, size_t low, size_t high, int value)
{
size_t mid, i;

if (low > high)
return -1;

printf("Searching in array: ");
for (i = low; i <= high; i++)
{
if (i == high)
printf("%d\n", array[i]);
else
printf("%d, ", array[i]);
}

mid = (low + high) / 2;

if (array[mid] == value)
{
if (mid == low || array[mid - 1] != value)
return mid;
else
return advanced_binary_recursive(array, low, mid, value);
}
else if (array[mid] < value)
{
return advanced_binary_recursive(array, mid + 1, high, value);
}
else
{
return advanced_binary_recursive(array, low, mid, value);
}
}

/**
* advanced_binary - Searches for a value in a sorted array using
*                   advanced binary search
* @array: Pointer to the first element of the array to search in
* @size: Number of elements in the array
* @value: Value to search for
*
* Return: Index where value is located, or -1 if not found or array is NULL
*/
int advanced_binary(int *array, size_t size, int value)
{
if (array == NULL || size == 0)
return -1;

return advanced_binary_recursive(array, 0, size - 1, value);
}
