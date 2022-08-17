#include "shell.h"

/**
 * _strlen - this returns the length of a string.
 * @s: a Pointer to the string to measure.
 * Return: to the length of the string.
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
 *_strcpy -copies the string pointed to by src, including the null byte
 * null byte (\0), to the buffer pointed to by dest.
 * @dest: a pointer to the destination.
 * @src: a pointer to the origin.
 * Return: Pointer to dest
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
 * _strcat - this concatenates two strings.
 * @dest: a pointer to the destination string.
 * @src: a Pointer to the source string
 * Return: a Pointer to the resulting string dest
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
 * _strcmp - this compares 2 strings
 * @s1: a Pointer to the first string
 * @s2: a Pointer to the second string
 * Return: to the difference between the first 2 different ASCII characters
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
 *count_words -Count the words in each string,the words are separated by spaces.
 * @s: is a string to count words.
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
