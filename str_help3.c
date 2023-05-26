#include "shell.h"

/**
 * _isdigit -  a function that checks for a digit 0-9
 * @c: input
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
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

/**
 * _quit_atoi - this function closes the atoi function
 * @str: string to be exited
 *
 * Return: an integer
 */
int _quit_atoi(char *str)
{
	int n = 0, i = 0;
	int pid_max = 2147483647;

	if (str[i] == '-')
		return (1);
	while (str[i])
	{
		if (_isdigit(str[i]) == 1)
			n = n * 10 + str[i] - '0';
		else
			return (1);
		i++;
	}
	if (n > pid_max)
		return (1);
	else
		return (n);
}

/**
 * _realloc - this function reallocates a memory block using malloc
 * @ptr: this is the pointer to a memory block previously allocated with malloc
 * @old_size: this is the size in bytes of the allocated space for ptr
 * @new_size: this is the new size of the new memory block
 *
 * Return: returns nothing
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *nptr;
	size_t r;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	nptr = malloc(new_size);
	if (nptr == NULL)
		return (NULL);

	r = 0;
	while (r < old_size)
	{
		*((char *)ptr + r) = *((char *)nptr + r);
		r++;
	}
	free(ptr);
	return (nptr);
}
