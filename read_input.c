#include "shell.h"
/**
  * read_input - Read input from use
  * Return: always 0 (success)
  */
char *read_input(void)
{
	char *input = NULL;
	size_t len = 0;

	if (getline(&input, &len, stdin) == -1)
	{
		if (feof(stdin))
		{
			custom_print("\n");
			exit(0);
		}
		else
		{
			custom_print("Command not found. \n");
			exit(1);
		}
	}

	input[strcspn(input, "\n")] = '\0';

	return (input);
}
