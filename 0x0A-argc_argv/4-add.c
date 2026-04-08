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
 * _putint - prints an integer using _putchar (non-negative only)
 * @n: integer to print
 */
void _putint(int n)
{
	if (n / 10)
		_putint(n / 10);
	_putchar('0' + (n % 10));
}

/**
 * is_digit_string - checks if a string contains only digits
 * @s: string to check
 *
 * Return: 1 if all characters are digits, 0 otherwise
 */
int is_digit_string(char *s)
{
	if (*s == '\0')
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

/**
 * _atoi_positive - converts a digit string to integer (no sign)
 * @s: string of digits
 *
 * Return: integer value
 */
int _atoi_positive(char *s)
{
	int result = 0;

	while (*s)
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return (result);
}

/**
 * main - adds positive numbers passed as arguments
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int i, sum = 0;

	if (argc == 1)
	{
		_putint(0);
		_putchar('\n');
		return (0);
	}
	for (i = 1; i < argc; i++)
	{
		if (!is_digit_string(argv[i]))
		{
			_putstr("Error");
			_putchar('\n');
			return (1);
		}
		sum += _atoi_positive(argv[i]);
	}
	_putint(sum);
	_putchar('\n');
	return (0);
}
