#include "main.h"

/**
 * _strlen - compute the length of a string
 * @s: the string
 *
 * Return: number of characters before '\0'
 */
static unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * string_nconcat - concatenates s1 with first n bytes of s2
 * @s1: first string (can be NULL)
 * @s2: second string (can be NULL)
 * @n: maximum bytes to take from s2
 *
 * Return: pointer to newly allocated concatenated string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1, len2, i, j;
	char *cat;

	/* treat NULL as empty */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	/* limit n to the length of s2 */
	if (n >= len2)
		n = len2;

	/* allocate memory for s1 + n bytes + null terminator */
	cat = malloc(len1 + n + 1);
	if (cat == NULL)
		return (NULL);

	/* copy s1 */
	for (i = 0; i < len1; i++)
		cat[i] = s1[i];
	/* copy first n bytes of s2 */
	for (j = 0; j < n; j++)
		cat[i + j] = s2[j];
	/* null terminate */
	cat[i + j] = '\0';

	return (cat);
}
