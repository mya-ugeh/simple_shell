#ifndef SHELL_H
#define SHELL_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

void custom_print(const char *input);
void display_prompt(void);
char *read_input(void);
void exe_command(const char *input, const char *program_name);
char *trim_space(const char *input);
char *find_command(const char *command);
void exit_shell(void);

/**
  * struct CopyAndExecuteParams - A structure to hold parameters
  * @src_path: Path to the source file
  * @dst_path: Path to the destination file
  * @exec_path: Path to the copied executable
  * @exec_args: Array of arguments for executing the copied file
 */
typedef struct
{
        const char *src_path;
        const char *dst_path;
        const char *exec_path;
        const char *const *exec_args;
} CopyAndExecuteParams;



/**
 * copy_and_execute - Copy a file and execute the copied file
 * @params: Pointer to a CopyAndExecuteParams structure containing parameters
 *
 * This function copies the contents of the source file to the destination file,
 * and then it executes the copied file using execve.
 *
 * Return: 0 on success, -1 on failure
 */
int copy_and_execute(const CopyAndExecuteParams *params);



extern char **environ;



#endif /*SHELL_H */
