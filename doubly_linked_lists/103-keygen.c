#include <stdio.h>

/**
 * main - generates a valid key for crackme5
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	int sum = 0, i;

	if (ac != 2)
		return (1);

	for (i = 0; av[1][i] != '\0'; i++)
		sum += (unsigned char)av[1][i];

	printf("%d", sum * i);   /* sum * length, no newline */
	return (0);
}
