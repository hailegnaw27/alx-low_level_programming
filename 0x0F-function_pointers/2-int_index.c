#include "function_pointers.h"
#include <stdio.h>

/**
* int_index - searches for an integer in an array
* @array: the array to search in
* @size: the number of elements in the array
* @cmp: pointer to the comparison function
*
* Return: index of the first matching element, or -1 if no match or invalid input
*/
int int_index(int *array, int size, int (*cmp)(int))
{
if (array && cmp && size > 0)
{
int i;

for (i = 0; i < size; i++)
{
if (cmp(array[i]))
{
return (i);
            }
}
return (-1);
}
