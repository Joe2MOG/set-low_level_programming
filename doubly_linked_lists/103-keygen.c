#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - generates a valid 6-character key for crackme5
 *
 * HOW crackme5 VALIDATES THE KEY (reverse-engineered from binary):
 *
 *   The binary stores a 64-character lookup table:
 *     "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk"
 *
 *   It checks exactly 6 key characters. For each position i (0..5),
 *   it calls a helper function fi() which returns an INDEX into that table.
 *   The key character at position i must equal table[fi()].
 *
 *   The six index-computing functions (from disassembly):
 *     f1(len)         = (len ^ 0x3b) & 0x3f
 *     f2(user, len)   = (sum_of_ascii(user) ^ 0x4f) & 0x3f
 *     f3(user, len)   = (product_of_ascii(user) ^ 0x55) & 0x3f
 *     f4(user, len)   = srand(max_ascii(user) ^ 0x0e); rand() & 0x3f
 *     f5(user, len)   = (sum_of_squares(user) ^ 0xef) & 0x3f  [low byte XOR]
 *     f6(user)        = (rand() called username[0] times) ^ 0xe5 & 0x3f
 *                       NOTE: f6 uses the rand() state left by f4 — no srand reset
 *
 * @argc: argument count
 * @argv: argument vector — argv[1] is the username
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	/* 64-char lookup table extracted from binary (8 movabs of 8 bytes LE) */
	const char *table = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	const char *user;
	int         ulen;
	int         i;

	/* --- accumulators for each function --- */
	int sum;        /* f2: sum of ASCII values                  */
	int product;    /* f3: product of ASCII values              */
	int max_c;      /* f4: max ASCII value (used as srand seed) */
	int sq_sum;     /* f5: sum of (char * char)                 */

	/* --- the six table indices, one per key character --- */
	int idx[6];
	char key[7];    /* 6 chars + NUL terminator                 */

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s username\n", argv[0]);
		return (1);
	}

	user = argv[1];
	ulen = (int)strlen(user);

	/* ---- f1: index = (length XOR 0x3b) AND 0x3f ---- */
	idx[0] = (ulen ^ 0x3b) & 0x3f;

	/* ---- f2: index = (sum_of_ascii XOR 0x4f) AND 0x3f ---- */
	sum = 0;
	for (i = 0; i < ulen; i++)
		sum += (unsigned char)user[i];
	idx[1] = (sum ^ 0x4f) & 0x3f;

	/* ---- f3: index = (product_of_ascii XOR 0x55) AND 0x3f ---- */
	product = 1;
	for (i = 0; i < ulen; i++)
		product *= (unsigned char)user[i];
	idx[2] = (product ^ 0x55) & 0x3f;

	/* ---- f4: srand(max_ascii XOR 0x0e); index = rand() AND 0x3f ----
	   IMPORTANT: this seeds the global rand() state; f5 and f6 inherit it */
	max_c = (unsigned char)user[0];
	for (i = 0; i < ulen; i++)
		if ((unsigned char)user[i] > max_c)
			max_c = (unsigned char)user[i];
	srand((unsigned int)(max_c ^ 0x0e));
	idx[3] = rand() & 0x3f;

	/* ---- f5: index = (sum_of_squares XOR 0xef low byte) AND 0x3f ----
	   The binary uses "xor al, 0xef" — only the low byte of the sum is XORed */
	sq_sum = 0;
	for (i = 0; i < ulen; i++)
		sq_sum += (unsigned char)user[i] * (unsigned char)user[i];
	idx[4] = ((sq_sum ^ 0xef)) & 0x3f;

	/* ---- f6: call rand() username[0] times; index = (last ^ 0xe5) AND 0x3f ----
	   Uses the rand() state left by f4 — no srand() call here */
	{
		int last = 0;
		int count = (unsigned char)user[0]; /* loop runs while count > loop_var */

		for (i = 0; i < count; i++)
			last = rand();
		idx[5] = (last ^ 0xe5) & 0x3f;
	}

	/* ---- Build and print the 6-character key ---- */
	for (i = 0; i < 6; i++)
		key[i] = table[idx[i]];
	key[6] = '\0';

	printf("%s\n", key);
	return (0);
}
