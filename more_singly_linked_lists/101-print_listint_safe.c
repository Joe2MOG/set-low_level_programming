#include "lists.h"

/**
 * print_listint_safe - prints a listint_t list (handles loops)
 * @head: pointer to the head of the list
 *
 * Return: number of nodes printed
 * Exits with status 98 if memory allocation fails or list too long
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0, i;
	const listint_t *visited[1024];  /* fixed size, no malloc needed */
	const listint_t *current = head;

	while (current != NULL)
	{
		if (count == 1024)
			exit(98);

		for (i = 0; i < count; i++)
		{
			if (visited[i] == current)
			{
				printf("-> [%p] %d\n", (void *)current, current->n);
				return (count);
			}
		}

		visited[count] = current;
		printf("[%p] %d\n", (void *)current, current->n);
		count++;
		current = current->next;
	}
	return (count);
}
