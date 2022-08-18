#include "shell.h"
/**
 * nobuilt_in - execute non builtin functions of shell
 * @sll: typedef structure shell
 * @CommandPath: path enviroment of command
 * Return: int
 */
int nobuilt_in(sll_t *sll, char *CommandPath)
{
	int statusLock;
	char **arg_list = NULL;
	int totalCommand = sll->num_flags + 1;
	int i = 0;
	pid_t childPid;

	arg_list = malloc(sizeof(char *) * (totalCommand + 1));
	if (!arg_list)
		return (EXIT_FAILURE);
	while (i < totalCommand)
	{
		if (i == 0)
			arg_list[i] = _strdup(CommandPath);
		else
			arg_list[i] = _strdup(sll->flags[i - 1]);
		i++;
	}
	arg_list[i] = NULL;

	childPid = fork();
	if (childPid == 0)
		execv(CommandPath, arg_list);
	wait(&statusLock);


	if (arg_list)
	{
		for (i = 0; arg_list[i]; i++)
			free(arg_list[i]);
		free(arg_list);
	}
	return (EXIT_SUCCESS);
}
