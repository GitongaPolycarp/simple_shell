#ifndef SHELL_H
#define SHELL_H
/*
 *These are libraries to the underlying files
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

/*
 *The follong are function names to files.
 */
void disp_pmpt(void);
void shell_print(const char *result);
void get_cmd(char *cmd, size_t len);
void exec_cmd(const char *cmd);

#endif
