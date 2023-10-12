#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given index
 * @head: Double pointer to the head of the list
 * @index: Index of the node to delete
 *
 * Return: 1 if successful, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *previous;
	unsigned int i;

	if (*head == NULL)
	{
		return (-1); /* List is empty */
	}

	current = *head;
	previous = NULL;

	/* Traverse the list to the desired index */
	for (i = 0; i < index && current != NULL; i++)
	{
		previous = current;
		current = current->next;
	}

	if (i < index)
	{
		return (-1); /* Index out of range */
	}

	if (previous == NULL)
	{
		/* Deleting the first node */
		*head = current->next;
	}
	else
	{
		/* Updating the previous node's next pointer */
		previous->next = current->next;
	}

	if (current->next != NULL)
	{
		/* Updating the next node's prev pointer */
		current->next->prev = previous;
	}

	free(current);

	return (1); /* Node deleted successfully */
}

