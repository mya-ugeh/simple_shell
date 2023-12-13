#include "shell.h"
/**
  * custom_print - custom printf
  * @input: User input
  * Retuen: nothing
  */
void custom_print(const char *input)
{
	write(STDOUT_FILENO, input, strlen(input));
}
