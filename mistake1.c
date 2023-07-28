#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * stringToInt - converts a string to an integer
 * @s: the string to be converted
 *
 * Return: The converted number if successful, or -1 on error.
 */
int stringToInt(char *s)
{
int a = 0;
unsigned long int result = 0;

if (*s == '+')
	s++;

for (a = 0; s[a] != '\0'; a++)
{
	if (s[a] >= '0' && s[a] <= '9')
	{
	result *= 10;
		result += (s[a] - '0');
	if result > INT_MAX
			return (-1);
	}
	else
		return (-1);
}

return (result);
}

/**
 * printErrorInfo - prints an error message with information.
 * @info: The structure containing error information.
 * @errorType: The string containing the specified error type.
 *
 * Return: Nothing.
 */
void printErrorInfo(ino_t *info, char *errorType)
{
_printStringToStderr(info->filename);
_printStringToStderr(": ");
printDecimal(info->line_count, STDERR_FILENO);
_printStringToStderr(": ");
_printStringToStderr(info->argv[0]);
_printStringToStderr(": ");
_printStringToStderr(errorType);
}

/**
 * printDecimal - function prints a decimal (integer) number (base 10).
 * @input: the input number.
 * @fd: the file descriptor to write to.
 *
 * Return: The number of characters printed.
 */
int printDecimal(int input, int fd)
{
int (*__putchar)(char) = _putchar;
int a, count = 0;
unsigned int absValue, current;

if (fd == STDERR_FILENO)
	__putchar = _eputchar;

if (input < 0)
{
	absValue = -input;
	__putchar('-');
	count++;
}
else
	absValue = input;

current = absValue;
for (a = 1000000000; a > 1; a /= 10)
{
	if (absValue / a)
	{
		__putchar('0' + current / a);
		count++;
	}
	current %= a;
}
__putchar('0' + current);
count++;

return (count);
}

/**
 * convertToBase - function that converts a number to the specified base.
 * @num: The number to convert.
 * @base: The base to convert to.
 * @flags: Argument flags.
 *
 * Return: A string representing the converted number.
 */
char *convertToBase(long int num, int base, int flags)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
	n = -num;
	sign = '-';
}

array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';

do	{
	*--ptr = array[n % base];
	n /= base;
} while (n != 0);

if (sign)
	*--ptr = sign;

return (ptr);
}

/**
 * removeComments - function replaces the first instance of '#' with '\0'.
 * @buf: The address of the string to modify.
 *
 * Return: Always 0.
 */
void removeComments(char *buf)
{
int a;

for (a = 0; buf[a] != '\0'; a++)
	if (buf[a] == '#' && (!a || buf[a - 1] == ' '))
	{
		buf[a] = '\0';
		break;
	}
}
