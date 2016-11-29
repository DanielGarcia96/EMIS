#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int funct3(char *prog1, char *pargv[], char flag)
{
    int pip[2];
    if(pipe(pip) == -1)
    {
        perror("Piping error");
        return -1;
    }

    pid_t tpid = fork();
    switch(tpid)
    {
        case -1:
            perror("Forking error");
            return -1;
        break;
        case 0:
            if(flag == 'r')
            {
                close(pip[1]);
                dup2(pip[0], STDIN_FILENO);
            }
            else
            {
                close(pip[0]);
                dup2(pip[1], STDOUT_FILENO);
            }
            execvp(prog1, pargv);
            perror("Exec error");
            return -1;
        break;
    }

    if(flag == 'r')
        return pip[0];
    return pip[1];
}
