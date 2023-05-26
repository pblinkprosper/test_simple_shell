#include "shell.h"

/**
 * _putchar - this function writes a character to  the stdout
 * @ch: the character to be written
 *
 * Return: returns 1 on success and -1 on error
 */
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}

/**
 * _puts - this function prints a string to the stdout
 * @ch: the string parameter to be printed
 *
 * Return: void (nothing)
 */
void _puts(char *ch)
{
	int i;

	for (i = 0; ch[i] != '\0'; i++)
	{
		_putchar(ch[i]);
	}
	_putchar('\n');
}

/**
 * _strcmp - this function compares two strings
 * @s1: first string to be compared
 * @s2: second string for comparison
 *
 * Return: an integer
 */
int _strcmp(char *s1, char *s2)
{
	int r;
	int n;

	r = 0;
	while (s1[r] == s2[r] && (s1[r] != '\0' || s2[r] != '\0'))
	{
		r++;
	}
	n = s1[r] - s2[r];
	return (n);
}

/**
 * _strdup - this function duplicates a given string
 * @str: main string to be examined
 *
 * Return: a pointer to a character
 */
char *_strdup(const char *str)
{
	size_t f, g;
	char *ptr;

	if (str == NULL)
		return (0);
	for (f = 0; str[f]; f++)
		return (NULL);
	ptr = malloc(sizeof(char) * (f + 1));
	if (ptr == NULL)
		return (NULL);
	f = 0;
	g = 0;
	while (g < f)
	{
		ptr[g] = str[g];
		g++;
	}
	ptr[g] = '\0';
	return (ptr);
}

/**
 * _strchr - this function locates a character in a string
 * @s: pointer to the string
 * @c: character to be located
 *
 * Return: return the pointer to the character
 */
char *_strchr(char *s, char *c)
{
	for (; *s; s++)
	{
		if (*s == *c)
		{
			return ((char *)(s));
		}
	}
	return (NULL);
}
