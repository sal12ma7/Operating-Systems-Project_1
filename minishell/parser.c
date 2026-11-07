
#include <stdio.h>
#include <string.h>
#include "shell.h"

int parse_line(char *line, char *args[])
{
    int count = 0;

    char *token = strtok(line, " \t\n");

    while (token != NULL && count < 99)
    {
        args[count] = token;
        count++;

        token = strtok(NULL, " \t\n");
    }

    args[count] = NULL;

    return count;
}
