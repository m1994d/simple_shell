#include "main.h"


/**
 * tokenize_line - tokenizes line of arguments
 * @line: pointer to line from getline
 * Return: tokenized line
 */

char **tokenize_line(char *line)
{
	int buff_std = buffSTD, i = 0;
	char *temp_token = NULL;
	char **token = malloc(buff_std * sizeof(char *));

	if (token == NULL)
		exit(-1);
	temp_token = strtok(line, " \t\n");

	while (temp_token)
	{
		token[i] = temp_token;
		i++;

		temp_token = strtok(NULL, " \t\n");
	}
	token[i] = NULL;

	return (token);
}

/**
 * tokenize_path - tokenizes PATH
 * @line: pointer to PATH from env
 * Return: tokenized path
 */

char **tokenize_path(char *line)
{
	int buff_std = buffSTD, i = 0;
	char *temp_token = NULL;
	char **token = malloc(buff_std * sizeof(char *));

	if (token == NULL)
		exit(-1);
	temp_token = strtok(line, ":");

	while (temp_token)
	{
		token[i] = temp_token;
		i++;

		temp_token = strtok(NULL, ":");
	}
	temp_token = NULL;
	token[i] = NULL;

	return (token);
}
