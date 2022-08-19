#include "shell.h"

/**
 * free_elements - frees elements
 * @free1: pointer to string
 * @free2: double pointer to string
 */

void free_elements(char *free1, char **free2)
{
	free(free1);
	free(free2);
}
