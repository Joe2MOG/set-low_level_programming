#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t list and returns its data
 * @head: double pointer to the head of the list
 *
 * Return: the data of the removed node, or 0 if list empty
 */
int pop_listint(listint_t **head)
{
	listint_t *old_head;
	int data;

	if (head == NULL || *head == NULL)
		return (0);

	old_head = *head;
	data = old_head->n;
	*head = old_head->next;
	free(old_head);

	return (data);
}
