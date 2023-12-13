#include "shell.h"
int copy_and_execute(const CopyAndExecuteParams *params);
int copy_and_execute(const CopyAndExecuteParams *params)
{
	int src_fd, dst_fd, exec_fd;
	ssize_t n;
	char buffer[4096];

	src_fd = open(params->src_path, O_RDONLY);
	if (src_fd == -1)
	{
		perror("open source file");
		return (-1);
	}

	dst_fd = open(params->dst_path, O_CREAT | O_WRONLY, 0666);
	if (dst_fd == -1)
	{
		perror("open destination file");
		close(src_fd);
		return (-1);
	}

	while ((n = read(src_fd, buffer, sizeof(buffer))) > 0)
	{
		if (write(dst_fd, buffer, n) != n)
		{
			perror("write destination file");
			close(src_fd);
			close(dst_fd);
			return (-1);
		}
	}

	if (n == -1)
	{
		perror("read source file");
		close(src_fd);
		close(dst_fd);
		return (-1);
	}

	close(src_fd);
	close(dst_fd);

	exec_fd = open(params->exec_path, O_RDONLY);
	if (exec_fd == -1)
	{
		perror("open copied file for execution");
		return (-1);
	}

	if (execve(params->exec_path, (char *const *)params->exec_args, NULL) == -1)
	{
		perror("execve");
		close(exec_fd);
		return (-1);
	}
	close(exec_fd);
	return (0);
}
