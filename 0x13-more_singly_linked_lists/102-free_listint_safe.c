#include <stdlib.h>
#include "lists.h"

/**
* free_listint_safe - Frees a listint_t linked list.
* @h: Pointer to a pointer to the head node of the list.
*
* Return: The size of the list that was freed.
*/
size_t free_listint_safe(listint_t **h)
{
listint_t *slow = *h;
listint_t *fast = *h;
size_t count = 0;

while (fast != NULL && fast->next != NULL)
{
slow = slow->next;
fast = fast->next->next;
count++;

if (slow == fast)
{
*h = NULL;
while (*h != slow)
{
*h = slow->next;
free(slow);
slow = *h;
count++;
}
free(slow);
count++;
return (count);
}
}

*h = NULL;
while (slow != NULL)
{
*h = slow->next;
free(slow);
slow = *h;
count++;
}

return (count);
}
