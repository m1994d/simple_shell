#include "main.h"

/**
 * is_built_in - struct to find built in function
 * @args: arguments
 * Return: NULL if not found
 */

int (*is_built_in(char **args))(char **tokenized)
{
	size_t i = 0;
	builtin_t commands_built[] = {
		{"cd", exe_cd},
		{"help", exe_help},
		{"exit", exe_exit},
		{"env", exe_env},
		{NULL, NULL}};

	while (commands_built[i].command != NULL)
	{
		if (_strcmp(commands_built[i].command, args[0]) == 0)
			return (commands_built[i].command_func);
		i++;
	}
	return (NULL);
}
