#include "shell.h"

/**
 * shell_history_a - displays history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Struct contains potential args. maintains const funct prototype.
 *  Return: Always 0
 */
int shell_history_a(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * shell_unset_a - sets alias to str
 * @info: parameter 
 * @str: str alias
 *
 * Return: Always 0 on success, 1 on fail
 */
int shell_unset_a(info_t *info, char *str)
{
	char *p, b;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	b = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = b;
	return (ret);
}

/**
 * shell_set_a - sets alias to str
 * @info: parameter 
 * @str: the str
 *
 * Return: Always 0 on success, 1 fail
 */
int shell_set_a(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (shell_unset_a(info, str));

	shell_unset_a(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * shell_print_a - prints alias str
 * @node: alias node
 *
 * Return: Always 0 on success, 1 fail
 */
int shell_print_a(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * shell_myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */
int shell_myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			shell_print_a(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			shell_set_a(info, info->argv[i]);
		else
			shell_print_a(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
