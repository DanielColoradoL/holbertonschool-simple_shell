#ifndef SHELL
#define SHELL

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

char *_getline(void);
char **_argv_array(char *string);
void _print_env(void);

#endif

