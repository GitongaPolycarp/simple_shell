#include "shell.h"
/**
 * shell_print -  the function prints an output.
 * @result: gives the out from the func.
 */
void shell_print(const char *result)
{
	write(STDOUT_FILENO, result, strlen(result));
}


