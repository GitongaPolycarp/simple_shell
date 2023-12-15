#include "shell.h"

/**
 * shell_env - prints current environ
 * @info: Structure contains arguments. Used to maintain
 * Return: Always 0
 */
int shell_env(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * shell_getenv - gets value of environ var
 * @info: Structure contains arg.
 * @name: str
 *
 * Return: value
 */
char *shell_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * shell_setenv - Initialize a new environ variable,or modify an existing one
 * @info: Structure contains args
 *  Return: Always 0
 */
int shell_setenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * shell_unsetenv - Remove an environment var
 * @info: Structure contains potential args.
 *  Return: Always 0
 */
int shell_unsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Struct contains args
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
