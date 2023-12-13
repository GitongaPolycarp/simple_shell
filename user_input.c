#include "shell.h"

/**
 * get_cmd - function gets the command.
 * @cmd: the command given
 * @len: the length of a character
 */

void get_cmd(char *cmd, size_t len)
{
	if (fgets(cmd, len, stdin) == NULL)
	{
		if (feof(stdin))
		{
			shell_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			shell_print("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	cmd[strcspn(cmd, "\n")] = '\0';
}
