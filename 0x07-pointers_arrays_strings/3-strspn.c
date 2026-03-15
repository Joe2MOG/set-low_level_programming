#include "main.h"

/**
 * _strspn - gets length of prefix substring consisting of only accept bytes
 * @s: string to search
 * @accept: string containing allowed bytes
 *
 * Return: number of bytes in initial segment of s that are in accept
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
