#include "main.h"

/**
 * _isalpha - Checks if a character is alphabetic
 * @c: The character to check (as an int)
 *
 * Return: 1 if c is a letter (lowercase or uppercase), 0 otherwise
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
