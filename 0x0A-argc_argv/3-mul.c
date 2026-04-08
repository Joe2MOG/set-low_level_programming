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
 * _putint - prints an integer using _putchar (handles negative)
 * @n: integer to print
 */
void _putint(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10)
		_putint(n / 10);
	_putchar('0' + (n % 10));
}

/**
 * _atoi - converts a string to an integer (handles sign and digits)
 * @s: string to convert
 *
 * Return: integer value (stops at first non-digit)
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;

	while (*s == ' ' || *s == '\t')
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return (sign * result);
}

/**
 * main - multiplies two numbers from command line
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int a, b, result;

	if (argc != 3)
	{
		_putstr("Error");
		_putchar('\n');
		return (1);
	}
	a = _atoi(argv[1]);
	b = _atoi(argv[2]);
	result = a * b;
	_putint(result);
	_putchar('\n');
	return (0);
}
