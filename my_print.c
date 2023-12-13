#include "shell.h"
/**
  * display_prompt - for diplaying teminal
  *
  * Return: nothing
  */
void display_prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}
