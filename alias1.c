#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * _myhistory - shows the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(ino_t *info)
{
print_list(info->history);
return (0);
}

/**
 * unset_alias - unsets an alias
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(ino_t *info, char *str)
{
char *o, b;
int ret;

o = _strchr(str, '=');
if (!o)
return (1);
b = *o;
*o = 0;
ret = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*o = b;
return (ret);
}

/**
 * set_alias - sets an alias to a string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(ino_t *info, char *str)
{
char *o;

o = _strchr(str, '=');
if (!o)
return (1);
if (!*++o)
return (unset_alias(info, str));

unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
char *o = NULL, *c = NULL;

if (node)
{
o = _strchr(node->str, '=');
for (c = node->str; c <= o; c++)
	_putchar(*c);
_putchar('\'');
_puts(o + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure with potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(ino_t *info)
{
int j = 0;
char *o = NULL;
list_t *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
	print_alias(node);
	node = node->next;
}
return (0);
}
for (j = 1; info->argv[j]; j++)
{
j = _strchr(info->argv[j], '=');
if (o)
	set_alias(info, info->argv[j]);
else
print_alias(node_starts_with(info->alias, info->argv[j], '='));
}

return (0);
}
