#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 *
 * @str: Input String
 *
 * Return: Returns null if string is not allocated or returns string allocated
 * in different mem location
 *
 */

char *_strdup(char *str)
{
	char *dupe;
	int i = 0;
	int size;

	if (str == NULL)
		return (NULL);

	for (size = 0; str[size]; size++)
		;

	dupe = (char *)malloc(sizeof(char) * (size + 1));
	if (dupe == NULL)
		return (NULL);

	for (; i <= size; i++)
	{
		dupe[i] = str[i];
	}
	return (dupe);
}

/**
 * _strlen - Counts the lenght of string
 *
 *
 * @s: Input string
 *
 * Return: Returns the value of the lenght var
 *
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return (i);
}
/**
 * _strcpy - Copy strings
 * @dest: Copy string location
 * @src: Input string
 * Return: String copy location
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = src[i];
	return (dest);
}

/**
 * _strcat - Print characters
 * @dest: Input string 1
 * @src: Input string 2
 * Return: Concatenated strings
 */

char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;
	while (*src)
		*p++ = *src++;
	*p = '\0';
	return (dest);
}
/**
 * _strncmp - compares two strings
 * @s1: string
 * @s2: string
 * @n: numbers of bytes
 *Return: comp
 */

int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;
	int comp = 0;

	if (i < n)
	{
		while (s1[i] && s2[i])
		{
			if (s1[i] == s2[i])
			{
				comp = 0;
				i++;
			}
			else
			{
				comp = s1[i] - s2[i];
				break;
			}
		}
	}
	return (comp);
}
