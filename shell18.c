#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: destination
 * @src: source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int d = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[d])
	{
		dest[d] = src[d];
		d++;
	}
	dest[d] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	for (len++; len--;)
		ret[len] = *--str;
	return (ret);
}

/**
 *_puts - prints input string
 *@str: string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int d = 0;

	if (!str)
		return;
	while (str[d] != '\0')
	{
		_putchar(str[d]);
		d++;
	}
}

/**
 * _putchar - writes char c to stdout
 * @c: char to print
 *
 * Return: 1 On success
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int d;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || d >= WRITE_BUF_SIZE)
	{
		write(1, buf, d);
		d = 0;
	}
	if (c != BUF_FLUSH)
		buf[d++] = c;
	return (1);
}
