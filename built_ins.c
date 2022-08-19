#include "main.h"

/**
 * exe_cd - built in function for cd
 * @args: arguments
 * Return: 1
 */

int exe_cd(char **args)
{
	if (args[1] == NULL)
		perror("Expected path to cd");
	else
	{
		if (chdir(args[1]) != 0)
			perror("Could not change directory");
	}

	return (1);
}

/**
 * exe_help - built in function for help
 * @args: arguments
 * Return: 1
 */

int exe_help(char **args)
{
	(void)(args);

	printf("Type [Command] where command is the program that");
	printf(" you want to execute\n");

	return (1);
}

/**
 * exe_exit - built in function for exit
 * @args: arguments
 * Return: 1
 */

int exe_exit(char **args)
{
	(void)(args);

	return (EXIT_SUCCESS);
}

/**
 * exe_env - built in function for env
 * @args: arguments
 * Return: 1
 */

int exe_env(char **args)
{
	int i = 0, j = 0;
	(void)(args);

	while (environ[i])
	{
		for (j = 0; environ[i][j]; j++)
			_putchar(environ[i][j]);
		_putchar(10);
		i++;
	}
	return (1);
}
