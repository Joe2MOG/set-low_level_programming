#include "main.h"

/**
 * _strncat - concatenates two strings
 * using at most n bytes from src
 * @dest: destination
 * @src: source
 * @n: maximum bytes from src
 *
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	char *ptr = dest;
	int i = 0;

	while (*ptr)
		ptr++;
	while (*src && i < n)
	{
		*ptr = *src;
		ptr++;
		src++;
		i++;
	}
	*ptr = '\0';
	return (dest);
}
