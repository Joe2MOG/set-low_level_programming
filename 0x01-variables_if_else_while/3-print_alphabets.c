#include <stdio.h>

/**
 * main - Prints lowercase then uppercase alphabet
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter;

	/* Print lowercase */
	for (letter = 'a'; letter <= 'z'; letter++)
		putchar(letter);

	/* Print uppercase */
	for (letter = 'A'; letter <= 'Z'; letter++)
		putchar(letter);

	putchar('\n');
	return (0);
}
