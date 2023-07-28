#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * copyStringN - copies a string up to a specified length.
 * @dest: The destination string to be copied to.
 * @src: The source string.
 * @n: The number of characters to be copied.
 *
 * Return: The pointer to the destination string.
 */
char *copyStringN(char *dest, char *src, int n)
{
int a, b;
char *s = dest;

a = 0;
while (src[a] != '\0' && a < n - 1)
{
dest[a] = src[a];
	a++;
}

if (a < n)
{
	b = a;
	while (b < n)
	{
		dest[b] = '\0';
		b++;
	}
}

return (s);
}

/**
 * concatenateStringN - concatenates two strings up to a specified length.
 * @dest: The first string.
 * @src: The second string.
 * @n: The maximum number of bytes to be used.
 *
 * Return: The pointer to the concatenated string.
 */
char *concatenateStringN(char *dest, char *src, int n)
{
int a, b;
char *s = dest;

a = 0;
while (dest[a] != '\0')
	a++;

b = 0;
while (src[b] != '\0' && b < n)
{
	dest[a] = src[b];
	a++;
	b++;
}

if (b < n)
	dest[a] = '\0';

return (s);
}

/**
 * findCharacter - locates a character in a string.
 * @s: The string to be parsed.
 * @c: The character to look for.
 *
 * Return: A pointer to the memory area s containing the character c,
 *         or NULL if the character is not found.
 */
char *findCharacter(char *s, char c)
{
do {
	if (*s == c)
		return (s);
} while (*s++ != '\0');

return (NULL);
}
