#include "main.h"
/**
 * exec_fxn - execve non builtins
 * @toks: tokenized user input
 * @argv: argument vector
 * Return: 0 on success
 */
int exec_fxn(char **toks, char **argv)
{
	pid_t pid;
	int value = 0, status;
	char *cmd;
	struct stat st;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (127);
	}
	if (pid == 0)
	{
		if (stat(toks[0], &st) == 0)
		{
			value = execve(toks[0], toks, environ);
			if (value == -1)
				perror("Execve"), exit(0);
			/*else
				exit(EXIT_SUCCESS);*/
		}
		else
		{
			cmd = find_path(toks[0]);
			if (cmd == NULL)
			{
				printf("Hey, write command -not-found fxn\n");
				exit(0);
			}
			else
			{
				value = execve(cmd, toks, environ);
				if (value == -1)
					/*free(cmd), */perror("Execve")/*, exit(0)*/;
				/*else
					exit(EXIT_SUCCESS);*/
			}
		}
	}
	else
		wait(&status);
	return (0);
}
