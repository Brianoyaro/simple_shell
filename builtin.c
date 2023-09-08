#include "main.h"
/**
 * builtin - handles custom shell builtins
 * @tks: tokenized user input
 * @tk: user input untokenized
 * @argv: argument vector
 * @count: loop iteration number
 * Return: 0 on builtin
 * -1 on non builtin
 */
int builtin(char **tks, char *tk, char **argv, int count)
{
	pid_t pid;
	int r_val = 1;

	if (strcmp(tks[0], "env") == 0)
	{
		env_fxn();
		r_val = 0;
	}
	if (strcmp(tks[0], "exit") == 0)
	{
		exit_fxn(tks, tk, argv, count);
		r_val = 0;
	}
	/*handle echo $$ as a builtin*/
	if (strcmp(tks[0], "echo") == 0 && strcmp(tks[1], "$$") == 0)
	{
		pid = getpid();
		printer(pid);
		write(STDOUT_FILENO, "\n", 1);
		r_val = 0;
	}
	return (r_val);
}
