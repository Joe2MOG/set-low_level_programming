#include "main.h"

/**
 * print_rev - Prints a string in reverse, followed by a new line
 * @s: Pointer to the string
 *
 * Return: void
 */
void print_rev(char *s)
{
	char *end = s;

	/* Find the end of the string */
	while (*end != '\0')
	{
		end++;
	}
	/* Move back one step to the last character */
	end--;

	/* Print from the last character back to the first */
	while (end >= s)
	{
		_putchar(*end);
		end--;
	}
	_putchar('\n');
}
