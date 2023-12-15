#include "shell.h"

/**
 * shell_exit - exits shell
 * @info: Struct contains arg. Used to maintain constant func prototype.
 *  Return: exits given exit status
 *         (0) if info.argv[0] != "exit"
 */
int shell_exit(info_t *info)
{
	int exitc;

	if (info->argv[1])
	{
		exitc = _erratoi(info->argv[1]);
		if (exitc == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * shell_cd - function changes current directory of the process
 * @info: Struct contains args. Used to maintain const funct prototype.
 *  Return: Always 0
 */
int shell_cd(info_t *info)
{
	char *n, *dir, buffer[1024];
	int chdir_ret;

	n = getcwd(buffer, 1024);
	if (!n)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = shell_getenv(info, "HOME=");
		if (!dir)
			chdir_ret = 
				chdir((dir = shell_getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!shell_getenv(info, "OLDPWD="))
		{
			_puts(n);
			_putchar('\n');
			return (1);
		}
		_puts(shell_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = 
			chdir((dir = shell_getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", shell_getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * shell_help - changes current directory of the process
 * @info: Struct contains args. Used to maintain const function prototype.
 *  Return: Always 0
 */
int shell_help(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Funct not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
