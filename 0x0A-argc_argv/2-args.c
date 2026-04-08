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
 * main - prints all command line arguments
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		_putstr(argv[i]);
		_putchar('\n');
	}
	return (0);
}
