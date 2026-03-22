#include "main.h"

/**
 * prime_helper - checks if n is prime using recursion
 * @n: number to check
 * @divisor: current divisor to test
 *
 * Return: 1 if prime, 0 otherwise
 */
int prime_helper(int n, int divisor)
{
	if (n <= 1)
		return (0);
	if (divisor == 1)
		return (1);
	if (n % divisor == 0)
		return (0);
	return (prime_helper(n, divisor - 1));
}

/**
 * is_prime_number - returns 1 if the input integer is a prime number
 * @n: integer
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (prime_helper(n, n / 2));
}
