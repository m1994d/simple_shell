#include "shell.h"

/**
 * _strlen - returns the length of a string.
 * @s: Pointer to string to measure
 * Return: Lenght of the string
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
 * @dest: Pointer to destiny
 * @src: Pointer to source
 * Return: pointer to dest
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

/**
 * _strcat - concatenates two strings.
 * @dest: Pointer to destination string
 * @src: Pointer to source string
 * Return: Pointer to resulting string dest
 */

char *_strcat(char *dest, char *src)
{
	int lendest;
	int lensrc;
	int lenfdest;
	int i;

	lendest = _strlen(dest);
	lensrc = _strlen(src);
	lenfdest = lendest + lensrc;
	i = 0;
	while (lendest <= lenfdest)
	{
		*(dest + lendest) = *(src + i);
		lendest++;
		i++;
	}
	return (dest);
}

/**
 * _strcmp - compares 2 strings
 * @s1: Pointer to first string
 * @s2: Pointer to second string
 * Return: The difference between the 2 first different characters in ASCII
 */

int _strcmp(char *s1, char *s2)
{
	int i;
	int ret;

	ret = 0;
	for (i = 0 ; *(s1 + i) != '\0' ; i++)
	{
		if (*(s1 + i) != *(s2 + i))
		{
			ret = *(s1 + i) - *(s2 + i);
			break;
		}
	}
	return (ret);
}

/**
 * count_words - Count words of a string, and words are separated by spaces
 * @s: String to count words
 * Return: Number of words
 */

int count_words(char *s)
{
	int ret, i;

	ret = 0;
	if (s == NULL)
		return (ret);
	for (i = 0; s[i]; i++)
	{
		if (s[i] == ' ' || s[i] == '	')
			ret++;
	}
	return (ret);
}
