#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t list
 * @head: pointer to the head of the list
 * @index: index of the node, starting at 0
 *
 * Return: pointer to the node, or NULL if it doesn't exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head != NULL && i < index)
	{
		head = head->next;
		i++;
	}
	/* if i == index, we are at the right node; else head is NULL */
	return (i == index ? head : NULL);
}
