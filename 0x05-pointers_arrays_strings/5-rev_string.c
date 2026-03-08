#include "main.h"

/**
 * rev_string - Reverses a string in place
 * @s: Pointer to the string
 *
 * Return: void
 */
void rev_string(char *s)
{
	char *start = s;
	char *end = s;
	char temp;

	/* Move end to the last character */
	while (*end)
		end++;
	end--; /* now end points to last character */

	/* Swap until pointers meet */
	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}
