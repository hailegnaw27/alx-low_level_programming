#include <stdlib.h>
#include "main.h"

/**
* _realloc - reallocates a memory block using malloc and free
* @ptr: pointer to the memory previously allocated with malloc
* @old_size: the size, in bytes, of the allocated space for ptr
* @new_size: the new size, in bytes, of the new memory block
*
* Return: pointer to the newly allocated memory block, or NULL on failure
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *new_ptr, *old_ptr;
unsigned int i;

if (new_size == old_size)
return (ptr);

if (ptr == NULL)
{
new_ptr = malloc(new_size);
if (new_ptr == NULL)
return (NULL);
return (new_ptr);
}

if (new_size == 0)
{
free(ptr);
return (NULL);
}

new_ptr = malloc(new_size);
if (new_ptr == NULL)
return (NULL);

old_ptr = ptr;
for (i = 0; i < old_size && i < new_size; i++)
new_ptr[i] = old_ptr[i];

free(ptr);

return (new_ptr);
}
