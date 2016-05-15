#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int funct1(int n)
{
    pid_t tpid;
    char buffer[256];
    int index = 0, i;
    for(i=1; i<n; i++)
    {
        switch(fork())
        {
            case 0:
                index = i;
                tpid = getpid();
                sprintf(buffer, "%d\t%d\n", index, (int)tpid);
                sleep(10);
                write(STDOUT_FILENO, buffer, strlen(buffer));
                exit(0);
            break;
        }
    }

    tpid = getpid();
    sprintf(buffer, "%d\t%d\n", index, (int)tpid);
    write(STDOUT_FILENO, buffer, strlen(buffer));
    return 0;
}
