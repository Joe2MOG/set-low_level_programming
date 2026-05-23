#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list
 * @head: double pointer to the head of the list
 *
 * Return: pointer to the first node of the reversed list
 *
 * Only one loop and at most two variables are used.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *tmp;

	if (head == NULL || *head == NULL)
		return (NULL);

	while (*head != NULL)
	{
		tmp = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = tmp;
	}
	*head = prev;
	return (prev);
}
