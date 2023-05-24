#include "shell.h"
/**
 * _strspn - function that calculates length of substring prefix
 * @s: the string to be scanned
 * @accept: string containing list of characters to match with string s
 *
 * Return: returns number of bytes in prefix of substring s which
 * consists of only the bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int m, n;

	for (m = 0; s[m]; m++)
	{
		for (n = 0; accept[n]; n++)
		{
			if (s[m] == accept[n])
				break;
		}
		if (accept[n] == '\0')
			return (m);
	}
	return (m);
}

/**
 *_strcspn - computes segment of str1 which consists of characters not in str2
 *@str1: string to be searched
 *@str2: string to be used
 *
 *Return: the index at which a char in str1 exists in str2
 */

unsigned int _strcspn(char *str1, char *str2)
{
	unsigned int i;

	for (i = 0; str1[i]; i++)
	{
		if (_strchr(str2, str1))
			return (i);
	}
	return (i);
}

/**
 * _strncmp - this function compares two strings using a maximum number of char
 * @s1: string 1 to be compared
 * @s2: string 2 to be compared
 * @n: maximum number of characters to be compared
 *
 * Return: returns an integer
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (i);
}

