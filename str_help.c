#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: string variable
 * Return: length of string
 */
int _strlen(char *s)
{
	int i;
	int count;

	count = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		count++;
	}
	return (count);
}
/**
 * _strcat - appends one string to another
 *
 * @dest: destination string
 * @src: source string
 *
 * Return: appended string
 */
char *_strcat(char *dest, char *src)
{
	int i, len_dest, len_src;

	len_dest = _strlen(dest);
	len_src = _strlen(src);

	for (i = 0; i <= len_src; i++)
	{
		dest[len_dest + i] = src[i];
	}
	return (dest);
}
/**
 * _memcpy - copies memory area
 *
 * @dest: destination area
 * @src: source area
 * @n: amount of bytes
 *
 * Return: dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int i;

	for (i = 0; n > 0; i++)
	{
		dest[i] = src[i];
		n--;
	}
	return (dest);
}
/**
 * _strcpy - copies strings
 *
 * @dest: destination string
 * @src: source string
 *
 * Return: destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * _atoi - converts string to integer
 *
 * @s: string
 *
 * Return: int
 */
int _atoi(char *s)
{
	unsigned int n = 0;
	int c = 0, min = 1, isi = 0;

	while (s[c])
	{
		if (s[c] == 45)
		{
			min *= -1;
		}
		while (s[c] >= 48 && s[c] <= 57)
		{
			isi = 1;
			n = (n * 10) + (s[c] - '\0');
			c++;
		}
		if (isi == 1)
			break;
		c++;
	}
	n *= min;
	return (n);
}
