#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
* malloc_checked - allocates memory using malloc
* @b: size of memory to allocate
*
* Return: pointer to the allocated memory
* if malloc fails, the function terminates the process with status 98
*/
void *malloc_checked(unsigned int b)
{
void *ptr = malloc(b);

if (ptr == NULL)
{
exit(98);
}

return (ptr);
}
