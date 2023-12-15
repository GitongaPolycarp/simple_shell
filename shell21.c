#include "shell.h"

/**
 **_memset - func fils mem with constant bytes
 *@s: the ptr to mem area
 *@b: the byte to fill eith
 *@n: the num of bytes to get filled
 *Return: (s) a ptr to the mem area S
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - func frees str of str
 * @pp: str of sttrs
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - func relocates block of mem
 * @ptr: ptr to prev malloc'd block
 * @old_size: byte_size of prev block
 * @new_size: byte_size of new block
 *
 * Return: ptr of the block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
