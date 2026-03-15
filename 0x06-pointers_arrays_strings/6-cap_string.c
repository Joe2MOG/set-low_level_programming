#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string to modify
 *
 * Return: pointer to the resulting string
 */
char *cap_string(char *str)
{
	int i, j;
	char separators[] = " \t\n,;.!?\"(){}";
	int cap_next = 1;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (cap_next && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
			cap_next = 0;
		}
		else if (!cap_next)
		{
			for (j = 0; separators[j] != '\0'; j++)
			{
				if (str[i] == separators[j])
				{
					cap_next = 1;
					break;
				}
			}
		}
		else
			cap_next = 0;
	}
	return (str);
}
