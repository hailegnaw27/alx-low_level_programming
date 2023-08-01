#include "lists.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
* free_listint_safe - Frees a listint_t list.
* @h: Pointer to the head node of the list.
*
* Return: The size of the list that was freed.
*/
size_t free_listint_safe(listint_t **h)
{
listint_t *slow = *h, *fast = *h;
size_t count = 0;

if (h == NULL || *h == NULL)
return (0);

while (fast && fast->next)
{
slow = slow->next;
fast = fast->next->next;

if (slow == fast)
{
slow = *h;
while (slow != fast)
{
slow = slow->next;
fast = fast->next;
}
fast = fast->next; // Move fast one step ahead to get the last node of the loop
while (fast->next != slow)
{
fast = fast->next;
count++;
}
fast->next = NULL; // Break the loop

slow = *h;
while (slow)
{
fast = slow->next;
free(slow);
count++;
slow = fast;
}
*h = NULL;
return (count);
}
}

slow = *h;
while (slow)
{
fast = slow->next;
free(slow);
count++;
slow = fast;
}
*h = NULL;
return (count);
}
