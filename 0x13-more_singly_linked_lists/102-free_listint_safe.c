#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
* print_listint_safe - Prints a listint_t linked list.
* @head: Pointer to the head of the list.
*
* Return: The number of nodes in the list.
*/
size_t print_listint_safe(const listint_t *head)
{
size_t count = 0;
const listint_t *current = head;
const listint_t *next = NULL;

while (current != NULL)
{
count++;
printf("[%p] %d\n", (void *)current, current->n);
next = current->next;

if (next >= current)
{
printf("-> [%p] %d\n", (void *)next, next->n);
break;
}

current = next;
}

return (count);
}

/**
* free_listint_safe - Frees a listint_t linked list.
* @head: Double pointer to the head of the list.
*
* Return: The size of the list that was freed.
*/
size_t free_listint_safe(listint_t **head)
{
size_t count = 0;
listint_t *current = *head;
listint_t *next = NULL;

while (current != NULL)
{
count++;
next = current->next;
free(current);

if (next >= current)
break;

current = next;
}

*head = NULL;

return (count);
}
