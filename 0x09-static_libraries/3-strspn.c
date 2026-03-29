#include "main.h"

/**
 * _strspn - gets length of prefix substring
 * @s: string to search
 * @accept: bytes allowed
 *
 * Return: number of bytes in initial segment
 * of s that are in accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int i, found;

	while (*s)
	{
		found = 0;
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
			{
				found = 1;
				break;
			}
		}
		if (!found)
			break;
		count++;
		s++;
	}
	return (count);
}
