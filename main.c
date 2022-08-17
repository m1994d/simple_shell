#include "my_shell.h"
/**
 * main - build a shell
 * @argc: number of arguments
 * @argv: pointer to the address of arguments
 * @envs: environment
 * Return: int
 */
int main(int argc __attribute__((unused)),
char *argv[] __attribute__((unused)), char **envs)
{
	char *line = NULL;
	int count = 0;
	char *CommandPath = NULL, *envPath;
	sll_t *sll;

	envPath = getenv("PATH");
	signal(SIGINT, new_signal_handler); /*SIGINT = Interrupt the process*/

	while (true)
	{
		line = NULL;
		CommandPath = NULL;
		count++;

		if (isatty(STDIN_FILENO) == 1)
		{
			if (write(STDOUT_FILENO, "$ ", 2) == EOF) /* print the prompt*/
				exit(EXIT_FAILURE);
		}
		GETline(&line); /* Line provided by user*/
		sll = parse_sll(line);
		free(line);

		if (built_in(sll, envs))
			continue;

		CommandPath = getpath_sll(sll, envPath);
		if (!CommandPath)
		{
			printf("%s: %d: %s: not found\n", argv[0], count, sll->Command);
			free(CommandPath), ALLfree(sll);
			continue;
		}
		nobuilt_in(sll, CommandPath);
		free(CommandPath), ALLfree(sll);
	}
	return (EXIT_SUCCESS);
}
