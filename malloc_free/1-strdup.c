#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated duplicate of a string
 * @str: the input string
 *
 * Return: pointer to the new string, or NULL if str is NULL or malloc fails
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int len, i;

	if (str == NULL)
		return (NULL);

	/* compute length manually (no strlen to be self-contained & C89 clean) */
	for (len = 0; str[len] != '\0'; len++)
		;

	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)	/* copy including the '\0' */
		dup[i] = str[i];

	return (dup);
}
