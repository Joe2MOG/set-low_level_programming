#include "main.h"

/**
 * _putstr - prints a string using _putchar
 * @str: string to print
 */
void _putstr(char *str)
{
	while (*str)
		_putchar(*str++);
}

/**
 * main - prints its name (argv[0])
 * @argc: argument count (unused)
 * @argv: argument vector
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	(void)argc; /* silence unused parameter warning */
	_putstr(argv[0]);
	_putchar('\n');
	return (0);
}
