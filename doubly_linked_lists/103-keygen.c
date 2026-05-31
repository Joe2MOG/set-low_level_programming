#include <stdio.h>
#include <string.h>

/**
 * main - generates a key for crackme5
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	int sum = 0, i = 0;

	if (argc != 2)
		return (1);

	while (argv[1][i])
		sum += argv[1][i++];

	printf("%d", sum ^ i);
	return (0);
}
