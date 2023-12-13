#include "shell.h"
#include <sys/wait.h>

/**
 * exec_cmd - the function executes a given command.
 * @cmd: given command
 */


void exec_cmd(const char *cmd)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		shell_print("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{

		/* Parse the cmd and its arg */
		char *args[128]; /* Maximum 128 arguments (adjust as needed)*/
		int arg_count = 0;

		char *token = strtok((char *)cmd, " ");

		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL; /* Null-terminate the arg arr */

		/* Exec the cmd */
		execvp(args[0], args);

		/* If execvp fails, print error msg */
		shell_print("Error executing command.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		/*Parent process*/
		wait(NULL);
	}
}
