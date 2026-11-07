#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include "shell.h"

int main()
{
    char line[1024];
    char cwd[1024];
    char *args[100];

    while (1)
    {
        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            printf("%s$ ", cwd);
            fflush(stdout);
        }

        if (fgets(line, sizeof(line), stdin) == NULL)
        {
            printf("\n");
            break;
        }

        int count = parse_line(line, args);

        if (count > 0)
        {
            if (execute(args) == 0)
            {
                break;
            }
        }
    }

    return 0;
}
