#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#include "shell.h"

int execute(char *args[])
{
    if (strcmp(args[0], "exit") == 0)
    {
        return 0;
    }

    if (strcmp(args[0], "cd") == 0)
    {
        if (args[1] == NULL)
        {
            printf("cd: missing directory\n");
        }
        else if (chdir(args[1]) == -1)
        {
            perror("cd");
        }

        return 1;
    }

    if (strcmp(args[0], "kill") == 0)
    {
        if (args[1] == NULL)
        {
            printf("kill: missing PID\n");
        }
        else
        {
            pid_t pid = atoi(args[1]);

            if (kill(pid, SIGTERM) == -1)
            {
                perror("kill");
            }
            else
            {
                printf("Signal sent to process %d\n", pid);
            }
        }

        return 1;
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
    }
    else if (pid == 0)
    {
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    }
    else
    {
        int status;

        printf("Process ID: %d\n", pid);

        if (waitpid(pid, &status, 0) == -1)
        {
            perror("waitpid");
        }
        else
        {
            if (WIFEXITED(status))
            {
                printf("Process finished with exit code %d\n",
                       WEXITSTATUS(status));
            }
            else if (WIFSIGNALED(status))
            {
                printf("Process terminated by signal %d\n",
                       WTERMSIG(status));
            }
        }
    }

    return 1;
}
