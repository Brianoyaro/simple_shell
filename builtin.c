#include "main.h"
/**
 * builtin - handles custom shell builtins
 * @tks: tokenized user input
 * @tk: user input untokenized
 * @argv: argument vector
 * Return: 0 on builtin
 * -1 on non builtin
 */
int builtin(char **tks, char *tk, char **argv)
{
	int r_val = 1;

	if (strcmp(tks[0], "env") == 0)
	{
		env_fxn();
		r_val = 0;
	}
	if (strcmp(tks[0], "exit") == 0)
	{
		exit_fxn(tks, tk, argv);
		r_val = 0;
	}
	/*else
		r_val = exec_fxn(tks);*/
	return (r_val);
}
