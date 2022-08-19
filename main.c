#include "shell.h"

/**
 * main - simple shell
 * @argc: argument counter
 * @argv: arguments
 * Return: 0
 */

int main(int argc, char **argv)
{
	char *line = NULL, **tokenized = NULL;
	int (*func_builtin)(char **);
	int tty = 1, status = 1;


	signal(SIGINT, ctrl_c);

	if (isatty(STDIN_FILENO) == 0)
		tty = 0;

	do {
		if (tty == 1)
			write(STDOUT_FILENO, SIGN_S, _strlen(SIGN_S));
		fflush(stdin);
		/* READ */
		line = read_line();
		/* TOKEN INPUT */
		tokenized = tokenize_line(line);
		/*Built-in || No-Built-In*/
		if (tokenized[0])
			func_builtin = is_built_in(tokenized);
		else
		{
			free_elements(line, tokenized);
			continue;
		}
		/*Execute*/
		if (func_builtin == NULL)
			status = check_exec(tokenized, argc, argv, tty, line);
		else
			status = func_builtin(tokenized);
		free_elements(line, tokenized);
	} while (status);

	return (0);
}

/**
 * read_line - reads the line
 * Return: string of arguments
 */

char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}

/**
 * ctrl_c - handles the ctrl+c signal
 * @sig: signal
 */

void ctrl_c(int sig)
{
	(void)sig;
	_putchar('\n');
	write(STDOUT_FILENO, SIGN_S, _strlen(SIGN_S));
}
