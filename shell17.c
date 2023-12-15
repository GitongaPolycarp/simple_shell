#include "shell.h"

/**
 * _strlen - func gives the len of a str
 * @s: the str len to checks
 *
 * Return: int len of str
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - func performs compa of 2 strings.
 * @s1: the 1st string
 * @s2: the 2nd strang
 *
 * Return: negative success, positive, zero
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - func looks if nedle begins with haystack
 * @haystack: str to search
 * @needle: the sub_str to look for
 *
 * Return: address, else,  NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - func concatenates 2 strs
 * @dest: the destin  buffer
 * @src: the source buffer
 *
 * Return: *p to destin buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
