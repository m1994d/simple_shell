#include "shell.h"

/**
 * check_exec - checks access to execute command
 * @tokens: tokenized path
 * @argc: argument counter
 * @argv: arguments
 * @tty: isatty status
 * @line: line
 * Return: status
 */

int check_exec(char **tokens, int argc, char **argv, int tty, char *line)
{
	char *path_dir = NULL, *path = NULL, **token_path = NULL;
	int status = 1;

	if (access(tokens[0], X_OK) != 0)
	{
		path_dir = _strdup(look_for_path(tokens, argc, argv, tty, line));
		token_path = tokenize_path(path_dir);
		path = filter_path(token_path, tokens[0]);
		free_elements(path_dir, token_path);
		if (path != NULL)
		{
			status = exec_proc(tokens, path);
			free(path);
			return (status);
		}
		else
		{
			error_handling(argc, argv, tokens, tty, line);
		}
	}
	else
	{
		status = exec_proc(tokens, tokens[0]);
		return (status);
	}
	return (status);
}

/**
 * exec_proc - executes command
 * @args: arguments
 * @path: path
 * Return: 1
 */

int exec_proc(char **args, char *path)
{
	pid_t pid;
	int status, ret;

	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
	{
		ret = execve(path, args, environ);
		if (ret == -1)
		{
			perror("No access");
			exit(1);
		}
	}
	else
		wait(&status);

	return (1);
}
