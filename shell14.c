#include "shell.h"

/**
 * bfree - func fres a *p and nulls the addrs
 * @ptr: addrs of *p to be freed
 *
 * Return: (1) freed, else 0.
 */
int shellfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
