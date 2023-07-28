#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/**
 * is_interactive - checks if the shell is in interactive mode
 * @info: struct address containing shell information
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */
int is_interactive(ino_t *info)
{
	if (isatty(STDIN_FILENO) && info->readfd <= 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/**
 * is_delimiter - checks if a character is a delimiter
 * @c: the character to check
 * @delimiters: the string containing delimiters
 *
 * Return: 1 if the character is a delimiter, 0 otherwise
 */
int is_delimiter(char c, char *delimiters)
{
	while (*delimiters)
	{
		if (*delimiters == c)
			return (1);
		delimiters++;
	}
	return (0);
}

/**
 * is_alphabetic - checks if a character is alphabetic
 * @c: the character to check
 *
 * Return: 1 if the character is alphabetic, 0 otherwise
 */
int is_alphabetic(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/**
 * string_to_integer - converts a string to an integer
 * @s: the string to be converted
 *
 * Return: the converted integer, 0 if no numbers in the string
 */
int string_to_integer(char *s)
{
	int a, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (a = 0; s[a] != '\0' && flag != 2; a++)
	{
		if (s[a] == '-')
			sign *= -1;

		if (s[a] >= '0' && s[a] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[a] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
