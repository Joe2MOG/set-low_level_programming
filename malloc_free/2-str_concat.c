#include "main.h"

/**
 * str_concat - concatenates two strings into a new memory block
 * @s1: first string (can be NULL)
 * @s2: second string (can be NULL)
 *
 * Return: pointer to the concatenated string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *cat;
	unsigned int len1, len2, i, j;

	/* treat NULL as empty */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (len1 = 0; s1[len1] != '\0'; len1++)
		;
	for (len2 = 0; s2[len2] != '\0'; len2++)
		;

	cat = malloc((len1 + len2 + 1) * sizeof(char));
	if (cat == NULL)
		return (NULL);

	/* copy s1 */
	for (i = 0; i < len1; i++)
		cat[i] = s1[i];
	/* copy s2 */
	for (j = 0; j < len2; j++)
		cat[i + j] = s2[j];
	/* null terminate */
	cat[i + j] = '\0';

	return (cat);
}
