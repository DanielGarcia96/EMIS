#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int funct2(char *prog1, char *prog2)
{
    char *args1[] = {prog1, NULL};
    char *args2[] = {prog2, NULL};

    int pip[2];
    if(pipe(pip) == -1)
    {
        perror("Piping error");
        return -1;
    }

    int status;
    pid_t fpid = fork();
    switch(fpid)
    {
        case -1:
            perror("Forking error");
            return -1;
        break;
        case 0:
            close(pip[0]);
            dup2(pip[1], STDOUT_FILENO);
            execvp(args1[0], args1);
            perror("Exec error");
            return -1;
        break;
        default:
            close(pip[1]);
            dup2(pip[0], STDIN_FILENO);
            wait(&status);
            execvp(args2[0], args2);
            perror("Exec error");
            return -1;
    }
        return 0;
}
