#include "main.h"

/**
 * sqrt_helper - finds square root recursively
 * @n: number
 * @guess: current candidate
 *
 * Return: square root if found, else -1
 */
int sqrt_helper(int n, int guess)
{
	if (guess * guess == n)
		return (guess);
	if (guess * guess > n)
		return (-1);
	return (sqrt_helper(n, guess + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: integer
 *
 * Return: square root if exists, else -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (sqrt_helper(n, 0));
}
