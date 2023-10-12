#include "lists.h"

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *new_node, *current;
unsigned int i;

/* Allocate memory for the new node */
new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
return (NULL);

/* Set the data of the new node */
new_node->n = n;
new_node->prev = NULL;
new_node->next = NULL;

/* If the list is empty, insert the new node as the head */
if (*h == NULL)
{
*h = new_node;
return (new_node);
}

/* If the new node should be inserted at the beginning */
if (idx == 0)
{
new_node->next = *h;
(*h)->prev = new_node;
*h = new_node;
return (new_node);
}

/* Traverse the list to find the node at index idx-1 */
current = *h;
for (i = 0; i < idx - 1 && current != NULL; i++)
current = current->next;

/* If the given index is out of range */
if (current == NULL)
{
free(new_node);
return (NULL);
}

/* Update the pointers to insert the new node */
new_node->next = current->next;
new_node->prev = current;
if (current->next != NULL)
current->next->prev = new_node;
current->next = new_node;

return (new_node);
}
