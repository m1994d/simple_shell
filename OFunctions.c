#include "shell.h"

/**
 * GETline - function to line the input provided by the user
 * @line: parameter to be read
 */

void GETline(char **line)

{
	size_t len = 0;
	ssize_t nread = 0;

	nread = getline(line, &len, stdin);
	if (nread == EOF)
	{
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		if (*line)
			free(*line);

		exit(EXIT_SUCCESS);
	}
}
