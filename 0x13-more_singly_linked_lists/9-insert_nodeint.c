#include <stdlib.h>
#include "lists.h"

/**
* insert_nodeint_at_index - Inserts a new node at a given position
* @head: Pointer to pointer to the head node
* @idx: Index of the list where the new node should be added (starts at 0)
* @n: Data for the new node
*
* Return: Address of the new node
*         NULL if it failed or if it is not possible to add the new node
*               at index idx
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
listint_t *new_node, *current;
unsigned int count = 0;

if (head == NULL)
return (NULL);

if (idx == 0)
return (add_nodeint(head, n));

current = *head;

while (current != NULL && count < idx - 1)
{
current = current->next;
count++;
}

if (current == NULL || current->next == NULL)
return (NULL);

new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->next = current->next;
current->next = new_node;

return (new_node);
}
