#include "main.h"
/**
 * _strcmp - compares two strings
 * @s1: char typr pointer
 * @s2: char type pointer
 * Return: difference in the values
 */
int _strcmp(char *s1, char *s2)
{
	int i, m;

	for (i = 0; s1[i] != '\0'; i++)
	{
		m = s1[i] - s2[i];
		if (m != 0)
			break;
	}
	if (m == 0)
		m = s1[i] - s2[i];
	return (m);
}
/**
 * _strcpy - copies src to dest
 * @dest: char type pointer
 * @src: char type pointer
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strlen - returns the length of a string
 * @s: char type string
 * Return: string length
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
