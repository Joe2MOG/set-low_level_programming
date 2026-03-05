#include "main.h"

/**
 * print_numbers - Prints the numbers 0 to 9, followed by a new line
 *
 * Return: void
 */
void print_numbers(void)
{
	int digit;

	for (digit = 0; digit <= 9; digit++)
	{
		_putchar('0' + digit);
	}
	_putchar('\n');
}
