#include "shell.h"

void exe_command(const char *input, const char *program_name)
{
	pid_t pid = fork();
	char *argv[4];

	if (pid < 0)
	{
		perror("fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		argv[0] = (char *)program_name;
		argv[1] = "-c";
		argv[2] = (char *)input;
		argv[3] = NULL;
		execvp("/bin/sh", argv);

		perror(program_name);
		exit(1);
	}
	else
		wait(NULL);
}
