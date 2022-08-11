#include "shell.h"

/**
 * _strlen - returns the length of a string.
 */

int _strlen(char *s)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (!s)
		return (len);
	while (*(s + i) != '\0')
	{
		len = len + 1;
		i++;
	}
	return (len);
}

/**
 * _strcpy - copies the string pointed to by src, including the terminating
 * null byte (\0), to the buffer pointed to by dest.
 */

char *_strcpy(char *dest, char *src)
{
	int len;
	int i;

	len = _strlen(src);
	for (i = 0; i <= len; i++)
		*(dest + i) = *(src + i);
	return (dest);
}
