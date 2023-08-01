#include <stdlib.h>
#include "lists.h"

/**
* free_listint_safe - Frees a listint_t linked list (safe version)
* @head: Double pointer to the head of the list
* Return: Number of nodes that were freed
*/
size_t free_listint_safe(listint_t **head)
{
size_t count = 0;
listint_t *current = *head;
listint_t *next_node = NULL;

while (current != NULL)
{
count++;

next_node = current->next;
free(current);

/* Check if next_node points back to a previous node */
if (next_node >= current)
{
break;
}

current = next_node;
}

*head = NULL;

return (count);
}
