#include "function_pointers.h"

/**
* array_iterator - executes a function on each element of an array
* @array: the array to iterate through
* @size: the size of the array
* @action: pointer to the function to execute
*
* Return: void
*/
void array_iterator(int *array, size_t size, void (*action)(int))
{
if (array && action)
{
size_t i;

for (i = 0; i < size; i++)
{
action(array[i]);
}
}
}

