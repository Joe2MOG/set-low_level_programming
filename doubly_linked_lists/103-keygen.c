#include <stdio.h>

/**
 * main - generates a valid key for crackme5
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	int sum = 0, i;

	if (argc != 2)
		return (1);

	for (i = 0; argv[1][i] != '\0'; i++)
		sum += argv[1][i];

	printf("%d", sum + i);   /* key = sum of ascii * length */
	return (0);
}
