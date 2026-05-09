#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>  /* for malloc, free, exit, size_t, NULL */
#include <stdio.h>   /* for printf (if needed) */

void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);

#endif /* MAIN_H */
