#ifndef SHELL_H
#define SHELL_H

int parse_line(char *line, char *args[]);
int execute(char *args[]);

#endif
