#ifndef _SHELL_H_
#define _SHELL_H_

#include <stddef.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
#define USE_GETLINE 0
#define USE_STRTOK 0
#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - a builtin string and related function
 * @type: the builtin commands flag
 * @func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(ino_t *);
} builtin_table;

int hsh(ino_t *, char **);
int find_builtin(ino_t *);
void find_cmd(ino_t *);
void fork_cmd(ino_t *);
int is_cmd(ino_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(ino_t *, char *, char *);
int loophsh(char **);
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
char **strtow(char *, char *);
char **strtow2(char *, char);
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
int bfree(void **);
int interactive(ino_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);
int _erratoi(char *);
void print_error(ino_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);
int _myexit(ino_t *);
int _mycd(ino_t *);
int _myhelp(ino_t *);
int _myhistory(ino_t *);
int _myalias(ino_t *);
size_t get_input(ino_t *);
int _getline(ino_t *, char **, size_t *);
void sigintHandler(int);
void clear_info(ino_t *);
void set_info(ino_t *, char **);
void free_info(ino_t *, int);
char *_getenv(ino_t *, const char *);
int _myenv(ino_t *);
int _mysetenv(ino_t *);
int _myunsetenv(ino_t *);
int populate_env_list(ino_t *);
char **get_environ(ino_t *);
int _unsetenv(ino_t *, char *);
int _setenv(ino_t *, char *, char *);
char *get_history_file(ino_t *info);
int write_history(ino_t *info);
int read_history(ino_t *info);
int build_history_list(ino_t *info, char *buf, int linecount);
int renumber_history(ino_t *info);
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
size_t get_node_index(list_t *, list_t *);
int is_chain(ino_t *, char *, size_t *);
void check_chain(ino_t *, char *, size_t *, size_t, size_t);
int replace_alias(ino_t *);
int replace_vars(ino_t *);
int replace_string(char **, char *);

#endif
