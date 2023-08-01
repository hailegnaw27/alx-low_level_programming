#include <stdlib.h>
#include "lists.h"

/**
* pop_listint - Deletes the head node of a listint_t linked list
* @head: Pointer to pointer to the head node
*
* Return: The head node's data (n)
*/
int pop_listint(listint_t **head)
{
listint_t *temp;

int data;

if (*head == NULL)

return (0);
temp = *head;
data = temp->n;

*head = (*head)->next;

free(temp);

return (data);
}
