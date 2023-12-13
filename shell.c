#include "shell.h"
/**
 * main - the functionindicates the main entry.
 *
 * Return: (void).
 */

int main(void)
{
	char cmd[120];

	while (true)
	{
		disp_pmpt();
		get_cmd(cmd, sizeof(cmd));
		exec_cmd(cmd);
	}



	return (0);
}
