#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string to modify
 *
 * Return: pointer to the resulting string
 */
char *cap_string(char *str)
{
	int i, j, is_sep;
	char separators[] = " \t\n,;.!?\"(){}";
	int new_word = 1;

	for (i = 0; str[i] != '\0'; i++)
	{
		is_sep = 0;
		/* check if current char is a separator */
		for (j = 0; separators[j] != '\0'; j++)
		{
			if (str[i] == separators[j])
			{
				is_sep = 1;
				break;
			}
		}
		if (is_sep)
		{
			new_word = 1;
		}
		else
		{
			if (new_word && str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
			new_word = 0;
		}
	}
	return (str);
}
