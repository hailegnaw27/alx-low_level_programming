#include "lists.h"
#include <stdio.h>

/**
* print_listint_safe - Prints a listint_t linked list.
* @head: Pointer to the head node of the list.
*
* Return: The number of nodes in the list.
*/
size_t print_listint_safe(const listint_t *head)
{
const listint_t *slow = head, *fast = head;
size_t count = 0;

if (head == NULL)
return (0);

while (fast && fast->next)
{
slow = slow->next;
fast = fast->next->next;

if (slow == fast)
{
slow = head;
while (slow != fast)
{
printf("[%p] %d\n", (void *)slow, slow->n);
slow = slow->next;
count++;
}
printf("[%p] %d\n", (void *)slow, slow->n);
count++;
return (count);
}

printf("[%p] %d\n", (void *)slow, slow->n);
slow = slow->next;
count++;
}

return (count);
}
