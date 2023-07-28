#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * printEnvironment - prints the current environment variables.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int printEnvironment(ino_t *info)
{
print_list_str(info->environment);
return (0);
}

/**
 * getEnvironmentValue - gets the value of an environment variable.
 * @info: Structure containing potential arguments. Used to maintain
 * @name: Environment variable name.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *getEnvironmentValue(ino_t *info, const char *name)
{
list_t *node = info->environment;
char *q;

while (node)
{
q = starts_with(node->str, name);
if (q && *q)
	return (q);
node = node->next;
}
return (NULL);
}

/**
 * setEnvironmentValue - Initialize a new environment variable,
 *                       or modify an existing one.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int setEnvironmentValue(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguments\n");
return (1);
}

if (_setenv(info, info->argv[1], info->argv[2]))
return (0);

return (1);
}

/**
 * unsetEnvironmentValue - Remove an environment variable.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int unsetEnvironmentValue(ino_t *info)
{
int p;

if (info->argc == 1)
{
_eputs("Too few arguments.\n");
return (1);
}

for (p = 1; p < info->argc; p++)
_unsetenv(info, info->argv[p]);

return (0);
}

/**
 * populateEnvironmentList - Populates environment linked list.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int populateEnvironmentList(ino_t *info)
{
list_t *node = NULL;
size_t p;

for (p = 0; environ[p]; p++)
add_node_end(&node, environ[p], 0);

info->environment = node;
return (0);
}
