#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>


/**
 * struct builtin - new typedef for struct
 * @command: string with command
 * @command_func: function to execute command
 */

typedef struct builtin
{
	char *command;
	int (*command_func)(char **args);
} builtin_t;

extern char **environ;

/*MACROS*/

#define SIGN_S "($H3LL) -> "
#define buffSTD 64
#define PATH_E "PATH="

/* handles ctrl_c */
void ctrl_c(int sig);
/*Duplicates a string*/
char *_strdup(char *str);
/*Tokenizer*/
char **tokenize_line(char *line);
/*Execute*/
int exec_proc(char **args, char *path);
/*Function to pointer*/
int (*is_built_in(char **args))(char **tokenized);
/*cd command*/
int exe_cd(char **args);
/*help command*/
int exe_help(char **args);
/*exit command*/
int exe_exit(char **args);
/*print env*/
int exe_env(char **args);

/* READS LINE */
char *read_line(void);
/*Look for the PATH*/
char *look_for_path(char **tokens, int argc, char **argv, int tty, char *line);
/*Tokenize PATH*/
char **tokenize_path(char *line);
/* Filther path */
char *filter_path(char **path, char *command);
/* Check if can be executed */
int check_exec(char **tokens, int argc, char **argv, int tty, char *line);
/* Free elements*/
void free_elements(char *free1, char **free2);
/* Handles errors */
void error_handling(int ac, char **av, char **tokenized, int tty, char *line);

/*Putchar*/
int _putchar(char c);

/*Strings*/
int _strncmp(char *s1, char *s2, int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);

/*Mem Handling*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif /*MAIN_HEADER*/
