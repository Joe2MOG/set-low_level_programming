#include <stdio.h>

/**
 * main - Prints all numbers of base 16 in lowercase
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char digit;

	/* Print digits 0-9 */
	for (digit = '0'; digit <= '9'; digit++)
		putchar(digit);

	/* Print letters a-f */
	for (digit = 'a'; digit <= 'f'; digit++)
		putchar(digit);

	putchar('\n');
	return (0);
}
