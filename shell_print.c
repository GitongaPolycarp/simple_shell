#include "shell.h"

void shell_print(const char *result)
{
    write(STDOUT_FILENO, result, strlen(result));
}


