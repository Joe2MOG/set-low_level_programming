#include "main.h"

/**
 * puts_half - Prints the second half of a string
 * @str: Pointer to the string
 *
 * Return: void
 */
void puts_half(char *str)
{
	int len = 0;
	int start;
	int i;

	/* Find the length of the string */
	while (str[len] != '\0')
	{
		len++;
	}

	/* Calculate starting index for second half */
	start = (len + 1) / 2;

	/* Print from start to end */
	for (i = start; i < len; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
