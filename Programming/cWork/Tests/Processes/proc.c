#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
    int i, procn = 0;
    for(i=1; i<10; i++)
    {
        int f = fork();
        if(f == -1)
        {
            perror("Forking error");
            exit(-1);
        }
        else if(f == 0)
        {
            procn = i;
            break;
        }
    }
 
    char msg[256];
    sprintf(msg,"Process %d\n", procn);
    write(STDOUT_FILENO, msg, strlen(msg));
    
    exit(0);
}
