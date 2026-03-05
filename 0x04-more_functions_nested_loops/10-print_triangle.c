#include "main.h"

/**
 * print_triangle - Prints a right‑aligned triangle of given size
 * @size: The size of the triangle
 *
 * Return: void
 */
void print_triangle(int size)
{
	int row, spaces, hashes;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (row = 0; row < size; row++)
	{
		/* Print leading spaces */
		for (spaces = 0; spaces < size - row - 1; spaces++)
		{
			_putchar(' ');
		}
		/* Print hashes */
		for (hashes = 0; hashes <= row; hashes++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
