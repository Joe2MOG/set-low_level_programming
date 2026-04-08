#include "main.h"

/**
 * _putint - prints an integer using _putchar
 * @n: the integer to print (non-negative)
 */
void _putint(int n)
{
	if (n / 10)
		_putint(n / 10);
	_putchar('0' + (n % 10));
}

/**
 * main - prints the number of arguments passed
 * @argc: argument count
 * @argv: argument vector (unused)
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	(void)argv;
	_putint(argc - 1);
	_putchar('\n');
	return (0);
}
