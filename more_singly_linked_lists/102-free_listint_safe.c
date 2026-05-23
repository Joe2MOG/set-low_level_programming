#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list (handles loops)
 * @h: double pointer to the head of the list
 *
 * Return: number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0, i;
	listint_t *visited[1024];
	listint_t *current, *prev = NULL;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	while (current != NULL)
	{
		if (count == 1024)
			exit(98);

		for (i = 0; i < count; i++)
		{
			if (visited[i] == current)
			{
				/* Loop found: break it and free all collected nodes */
				if (prev != NULL)
					prev->next = NULL;
				*h = NULL;
				for (i = 0; i < count; i++)
					free(visited[i]);
				return (count);
			}
		}

		visited[count] = current;
		count++;
		prev = current;
		current = current->next;
	}

	/* No loop: free all nodes linearly */
	for (i = 0; i < count; i++)
		free(visited[i]);

	*h = NULL;
	return (count);
}
