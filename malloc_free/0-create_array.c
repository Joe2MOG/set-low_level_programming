#include "main.h"

/**
 * create_array - creates an array of chars and initialises it with a char
 * @size: number of elements
 * @c: the character to initialise with
 *
 * Return: pointer to the array, or NULL on failure
 */
char *create_array(unsigned int size, char c)
{
	char *arr;
	unsigned int i;

	/* size 0 is a special case – return NULL */
	if (size == 0)
		return (NULL);

	arr = malloc(size * sizeof(char));
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		arr[i] = c;

	return (arr);
}
