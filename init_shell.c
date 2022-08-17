#include "shell.h"

/**
 * execute - Execute function for simple_shell
 * @argv: Argument vector
 * Return: 0 on succes execution, -1 on exit
 */

int execute(char **argv)
{
	if (_strcmp(argv[0], "env") == 0)
	{
		env_builtin();
		return (0);
	}
	execve(argv[0], argv, environ);
	return (0);
}

/**
 * get_errorline - gets error line from line and shell
 * @sh_command: Command used to run the shell
 * @line: Line runned
 * Return: Pointer to error line (must be freed)
 */

char *get_errorline(char *sh_command, char *line)
{
	char *ret, *aux;
	int total_len;

	if (line == NULL)
		return (NULL);
	total_len = _strlen(sh_command) + _strlen(line) + 20;
	ret = _calloc(sizeof(*ret), total_len);
	if (ret == NULL)
		return (NULL);
	_strcpy(ret, sh_command);
	aux = &ret[_strlen(sh_command)];
	_strcpy(aux, ": 1: ");
	aux = &aux[5];
	_strcpy(aux, line);
	aux = &aux[_strlen(line)];
	_strcpy(aux, ": not found\n");
	return (ret);
}

/**
 * env_builtin - prints the environment
 */


void env_builtin(void)
{
	int i;

	if (environ)
	{
		for (i = 0; environ[i]; i++)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
}


/**
 * init_shell - Fuction to execute simple shell
 * @prompt: Prompt to print
 * @sh_command: command used to execute the shell
 * @aux: Auxiliar size_t to getline
 * Return: 0 on success execution, 1 on malloc failure
 */

int init_shell(char *prompt, char *sh_command, size_t aux)
{
	char **argv, *errorline, *line = NULL;
	pid_t child_pid;
	ssize_t linelen = 0;
	int status, argvst, argc = 0;

	while (1)
	{
		ISATTYPROMPT(prompt, _strlen(prompt));
		line = _calloc(100, sizeof(*line));
		if (line == NULL)
			return (1);
		linelen = getline(&line, &aux, stdin);
		argc = count_words(line);
		if (linelen == 1 || argc == linelen - 1)
		{
			free(line);
			continue;
		}
		if (linelen == -1 || _strcmp(line, "exit\n") == 0)
			break;
		argv = _calloc((argc + 2), sizeof(*argv));
		if (argv == NULL)
			break;
		argvst = linetoargv(line, argv, linelen);
		errorline = get_errorline(sh_command, argv[0]);
		if (argvst >= 0)
		{
			child_pid = fork();
			if (child_pid == 0)
				execute(argv);
			else
				wait(&status);
			FREELAR(line, argvst, argv[0], argv, errorline);
		}
		else
			FREEWRITE(line, argv, errorline);
		ISATTYOUT;
	}
	free(line);
	return (0);
}

