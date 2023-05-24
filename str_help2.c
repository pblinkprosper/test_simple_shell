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
 * _strstr - this function locates the first occurence of a substring needle
 * in the string haystack
 * @haystack: main string to be examined
 * @needle: substring to be searched for in the haystack
 *
 * Return: a pointer to the first character found in the haystack else - NULL
 */
char *_strstr(char *haystack, char *needle)
{
	int f, g;

	for (f = 0; haystack[f]; f++)
	{
		for (g = 0; needle[g]; g++)
		{
			if (haystack[f + g] != needle[g])
				break;
		}
		if (!needle[g])
			return (haystack + f);
	}
	return (NULL);
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
