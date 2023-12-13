#include "shell.h"
/**
 * _myexit - exits shell
 * @info: Argument holder for consistent function signatures.
 *  Return: exits with a exit status
 *         (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int exit_status;

	if (info->argv[1])  /* If there is an exit arguement */
	{
		exit_status = _erratoi(info->argv[1]);
		if (exit_status == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = exit_status;
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
/**
 * _mycd - changes current directory of the process.
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */
int _mycd(info_t *info)
{
	char *dir;
	int chdir_ret;

	dir = _getenv(info, "HOME=");
	if (!dir)
	{
		dir = _getenv(info, "PWD=");
		if (!dir)
			dir = "/";
	}
	if (info->argv[1])
	{
		if (info->argv[1][0] == '-')
		{
			if (_strcmp(info->argv[1], "-") == 0)
			{
				dir = _getenv(info, "OLDPWD=");
				if (!dir)
				{
					_puts(dir);
					_putchar('\n');
					return (1);
				}
			}
		}
		else
			dir = info->argv[1];
	}
	chdir_ret = chdir(dir);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(NULL, 0));
	}
	return (0);
}
/**
 * _myhelp - changes the current directory of the process
 * @info: Structure contains potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
