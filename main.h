#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
void control(int n);
int toker(char *line, char **argv);
int builtin(char **tks, char *tk, char **argv);
void env_fxn(void);
void exit_fxn(char **tks, char *tk, char **argv);
char *find_path(char *first);
int exec_fxn(char **toks, char **argv, char *tk);
char *hand_hash(char *str);
int a_toi(char *str);
void err(char **tokens, char **argv);

#endif
