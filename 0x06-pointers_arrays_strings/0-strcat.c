#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	/* find the end of dest */
	while (*ptr)
		ptr++;

	/* copy src including null terminator */
	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0'; /* add null terminator (though src's null would have been copied? Actually we stop when *src is null, so we need to add it) */

	return (dest);
}
