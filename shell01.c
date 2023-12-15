#include "shell.h"

/**
 * shell_it - function gives true if shell is in interc.t mode
 * @info: structure address
 *
 * Return: 1 success, 0 fail
 */
int shell_it(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * shell_dl - looks if char is a delim
 * @c: char to look
 * @delim: delim string
 * Return: 1 success, 0 fail
 */
int shell_dl(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *shell_alpha - looks for alphabetic char
 *@c: The char to input
 *Return: 1 success, 0 fail
 */

int shell_alpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *shell_at - converts str to int
 *@s: str to be converted
 *Return: 0 success, else fail
 */

int shell_at(char *s)
{
	int b, num = 1, flag = 0, output;
	unsigned int result = 0;

	for (b = 0;  s[b] != '\0' && flag != 2; b++)
	{
		if (s[b] == '-')
			num *= -1;

		if (s[b] >= '0' && s[b] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[b] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (num == -1)
		output = -result;
	else
		output = result;

	return (output);
}
