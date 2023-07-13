#include "main.h"
#include <stdlib.h>

/**
* array_range - creates an array of integers
* @min: the minimum value
* @max: the maximum value
*
* Return: pointer to the newly created array, or NULL on failure
*/
int *array_range(int min, int max)
{
int *arr;
int size, i;

if (min > max)
return (NULL);

size = max - min + 1;
arr = malloc(sizeof(int) * size);
if (arr == NULL)
return (NULL);

for (i = 0; i < size; i++, min++)
arr[i] = min;

return (arr);
}
