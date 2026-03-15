#include "main.h"

/**
 * string_toupper - changes all lowercase letters to uppercase
 * @str: string to modify
 *
 * Return: pointer to the resulting string
 */
char *string_toupper(char *str)
{
	char *ptr = str;

	while (*ptr)
	{
		if (*ptr >= 'a' && *ptr <= 'z')
			*ptr -= 32;
		ptr++;
	}
	return (str);
}
