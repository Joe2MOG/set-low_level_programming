#include "main.h"

/**
 * print_most_numbers - Prints numbers 0-9 except 2 and 4, followed by new line
 *
 * Return: void
 */
void print_most_numbers(void)
{
	int digit;

	for (digit = 0; digit <= 9; digit++)
	{
		if (digit != 2 && digit != 4)
		{
			_putchar('0' + digit);
		}
	}
	_putchar('\n');
}
