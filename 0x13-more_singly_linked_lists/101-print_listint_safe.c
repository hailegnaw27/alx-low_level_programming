#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
* print_listint_safe - Prints a listint_t linked list (safe version)
* @head: Pointer to the head of the list
* Return: Number of nodes in the list
*/
size_t print_listint_safe(const listint_t *head)
{
size_t count = 0;
const listint_t *current = head;
const listint_t *next_node = NULL;

while (current != NULL)
{
count++;
printf("[%p] %d\n", (void *)current, current->n);

next_node = current->next;

/* Check if next_node points back to a previous node */
if (next_node >= current)
{
printf("-> [%p] %d\n", (void *)next_node, next_node->n);
break;
}

current = current->next;
}

return (count);
}
