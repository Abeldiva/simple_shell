#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * _printStringToStderr - Prints a string to the standard error (stderr).
 * @str: The string to be printed.
 *
 * Return: Nothing.
 */
void _printStringToStderr(char *str)
{
int a = 0;

if (!str)
	return;

while (str[a] != '\0')
{
	_putcharToStderr(str[a]);
	a++;
}
}

/**
 * _putcharToStderr - Writes a character to the standard error (stderr) stream.
 * @c: The character to print.
 *
 * Return: On success 1.
 *         On error, -1 is returned, and errno is set appropriately.
 */
int _putcharToStderr(char c)
{
static int a;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
	write(2, buf, a);
	a = 0;
}

if (c != BUF_FLUSH)
	buf[a++] = c;

return (1);
}

/**
 * _putCharToFD - Writes a character to the given file descriptor (fd).
 * @c: The character to print.
 * @fd: The file descriptor to write to.
 *
 * Return: On success 1.
 *         On error, -1 is returned, and errno is set appropriately.
 */
int _putCharToFD(char c, int fd)
{
static int a;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
{
	write(fd, buf, a);
	a = 0;
}

if (c != BUF_FLUSH)
	buf[a++] = c;

return (1);
}

/**
 * _printStringToFD - Prints a string to the given file descriptor (fd).
 * @str: The string to be printed.
 * @fd: The file descriptor to write to.
 *
 * Return: The number of characters put.
 */
int _printStringToFD(char *str, int fd)
{
int a = 0;

if (!str)
	return (0);

while (*str)
{
	a += _putCharToFD(*str++, fd);
}

return (a);
}
