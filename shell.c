#include "shell.h"
/**
  * main - entry point
  * Return: always 0 (success)
  */

void exit_shell(void)
{
	exit(0);
}

int main(void)
{
	char input[256];
	char *program_name = "hsh";
	size_t len;

	char *path = getenv("PATH");

	if (path == NULL || strlen(path) == 0)
		setenv("PATH", "/bin:/usr/bin", 1);

	while (1)
	{
		/*custom_print(program_name);*/
		/*custom_print("$ ");*/

		if (fgets(input, sizeof(input), stdin) == NULL)
			break;

		len = strlen(input);
		if (len > 0 && input[len - 1] == '\n')
		{
			input[len - 1] = '\0';
		}

		if (strcmp(input, "exit") == 0)
			break;

		exe_command(input, program_name);
	}

	return (0);
}
