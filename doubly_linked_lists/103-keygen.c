#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * get_table - returns the 64-char lookup table from crackme5
 *
 * Return: pointer to the table string
 */
static const char *get_table(void)
{
	return ("A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU"
		"+4mjW6fxqZeF3Qa1rPhdKIouk");
}

/**
 * f1 - index from username length
 * @ulen: length of username
 *
 * Return: table index
 */
static int f1(int ulen)
{
	return ((ulen ^ 0x3b) & 0x3f);
}

/**
 * f2 - index from sum of ASCII values
 * @user: username string
 * @ulen: length of username
 *
 * Return: table index
 */
static int f2(const char *user, int ulen)
{
	int sum;
	int i;

	sum = 0;
	for (i = 0; i < ulen; i++)
		sum += (unsigned char)user[i];
	return ((sum ^ 0x4f) & 0x3f);
}

/**
 * f3 - index from product of ASCII values
 * @user: username string
 * @ulen: length of username
 *
 * Return: table index
 */
static int f3(const char *user, int ulen)
{
	int product;
	int i;

	product = 1;
	for (i = 0; i < ulen; i++)
		product *= (unsigned char)user[i];
	return ((product ^ 0x55) & 0x3f);
}

/**
 * f4 - index via srand(max_ascii XOR 0x0e) then rand()
 * @user: username string
 * @ulen: length of username
 *
 * Return: table index (also seeds global rand state for f6)
 */
static int f4(const char *user, int ulen)
{
	int max_c;
	int i;

	max_c = (unsigned char)user[0];
	for (i = 0; i < ulen; i++)
		if ((unsigned char)user[i] > max_c)
			max_c = (unsigned char)user[i];
	srand((unsigned int)(max_c ^ 0x0e));
	return (rand() & 0x3f);
}

/**
 * f5 - index from sum of squares of ASCII values
 * @user: username string
 * @ulen: length of username
 *
 * Return: table index
 */
static int f5(const char *user, int ulen)
{
	int sq_sum;
	int i;

	sq_sum = 0;
	for (i = 0; i < ulen; i++)
		sq_sum += (unsigned char)user[i] * (unsigned char)user[i];
	return ((sq_sum ^ 0xef) & 0x3f);
}

/**
 * f6 - index by calling rand() user[0] times (uses f4's srand state)
 * @user: username string
 *
 * Return: table index
 */
static int f6(const char *user)
{
	int last;
	int count;
	int i;

	last = 0;
	count = (unsigned char)user[0];
	for (i = 0; i < count; i++)
		last = rand();
	return ((last ^ 0xe5) & 0x3f);
}

/**
 * main - generates a valid 6-character key for crackme5
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	const char *table;
	const char *user;
	int ulen;
	int idx[6];
	char key[7];
	int i;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s username\n", argv[0]);
		return (1);
	}

	user  = argv[1];
	ulen  = (int)strlen(user);
	table = get_table();

	idx[0] = f1(ulen);
	idx[1] = f2(user, ulen);
	idx[2] = f3(user, ulen);
	idx[3] = f4(user, ulen); /* seeds rand() state — must run before f6 */
	idx[4] = f5(user, ulen);
	idx[5] = f6(user);

	for (i = 0; i < 6; i++)
		key[i] = table[idx[i]];
	key[6] = '\0';

	printf("%s\n", key);
	return (0);
}
