#include <stdio.h>

/**
 * premain - prints a message before main is executed
 *
 * This function is declared with the constructor attribute,
 * so it runs automatically before main().
 */
void __attribute__((constructor)) premain(void)
{
	printf("You're beat! and yet, you must allow,\n"
	       "I bore my house upon my back!\n");
}
