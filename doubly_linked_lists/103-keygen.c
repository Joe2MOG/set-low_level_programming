#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * compute_indices - calculates the 6 key indices for crackme5
 * @user: username string
 * @len: length of username
 * @idx: array of 6 ints to store the computed indices
 */
void compute_indices(const char *user, int len, int *idx)
{
	int i, sum, prod, sq_sum, max_c, tmp, count;

	sum = 0;
	prod = 1;
	max_c = (unsigned char)user[0];
	for (i = 0; i < len; i++)
	{
		sum += (unsigned char)user[i];
		prod *= (unsigned char)user[i];
		if ((unsigned char)user[i] > max_c)
			max_c = (unsigned char)user[i];
	}

	/* f1: len ^ 0x3b */
	idx[0] = (len ^ 0x3b) & 0x3f;
	/* f2: sum ^ 0x4f */
	idx[1] = (sum ^ 0x4f) & 0x3f;
	/* f3: prod ^ 0x55 */
	idx[2] = (prod ^ 0x55) & 0x3f;

	/* f4: max_c ^ 0x0e, then rand() */
	srand((unsigned int)(max_c ^ 0x0e));
	idx[3] = rand() & 0x3f;

	/* f5: sum of squares ^ 0xef */
	sq_sum = 0;
	for (i = 0; i < len; i++)
	{
		tmp = (unsigned char)user[i];
		sq_sum += tmp * tmp;
	}
	idx[4] = (sq_sum ^ 0xef) & 0x3f;

	/* f6: rand() user[0] times, last ^ 0xe5 */
	tmp = 0;
	count = (unsigned char)user[0];
	for (i = 0; i < count; i++)
		tmp = rand();
	idx[5] = (tmp ^ 0xe5) & 0x3f;
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
	const char *user;
	int len, i;
	int idx[6];
	char key[7];
	const char table[] =
		"A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	if (argc != 2)
		return (1);

	user = argv[1];
	len = (int)strlen(user);
	compute_indices(user, len, idx);

	for (i = 0; i < 6; i++)
		key[i] = table[idx[i]];
	key[6] = '\0';

	printf("%s\n", key);
	return (0);
}
