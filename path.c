#include "shell.h"
/**
  * find_command - find command
  * command: command to find
  * Return: NULL
  */

char *find_command(const char *command)
{
	char *path = getenv("PATH");
	char *dir, *path_copy, *token;
	char full_path[256];

	if (path == NULL)
	{
		return (NULL);
	}

	path_copy = strdup(path);

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		dir = token;
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
		custom_print(token);

		if (access(full_path, F_OK) != -1)
		{
			free(path_copy);
			return (strdup(full_path));
		}

		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
