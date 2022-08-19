#include "shell.h"
/**
 * built_in - builtin functions of shell
 * @sll: shell structure
 * @envs: environements
 * Return: int
 */
int built_in(sll_t *sll, char **envs)
{
	if (_strcmp(sll->Command, "exit") == 0)
	{
		ALLfree(sll);
		exit(EXIT_SUCCESS);
	}

	if (_strcmp(sll->Command, "env") == 0)
	{
		while (*envs)
		{
			printf("%s\n", *envs);
			envs++;
		}
		ALLfree(sll);
		return (1);
	}

	if (_strcmp(sll->Command, "cd") == 0)
	{
		printf("I'm cd Command\n");
		ALLfree(sll);
		return (1);
	}

	return (0);
}

/**
 * Error_handler - function that handles errors
 * @cmd: input command
 * @argv: arguments from the terminal
 */

void Error_handler(sll_t *sll, char **argv)
{
	char *message = NULL, *commandPath = NULL;
	int count = 0;

	message = malloc(sizeof(char) * 100);
	sprintf(message, "%s: %d: %s: not found\n", argv[0], count, sll->Command);
	write(STDERR_FILENO, message, _strlen(message));

	free(commandPath), ALLfree(sll), free(message);
	if (isatty(STDIN_FILENO) != 1)
		exit(127);
}
