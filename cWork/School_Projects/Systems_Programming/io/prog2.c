#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF 1024

int main(int argc, char *argv[])
{
    int i, fd;
    char buf[BUF];
    size_t nbytes;

    for(i=1; i<=argc-1; i++)
    {
        if((fd = open(argv[i], O_RDONLY)) == -1)
        {
            perror("Error opening file");
            return -1;
        }

        while((nbytes = read(fd, buf, BUF)) > 0)
        {
            if(write(STDOUT_FILENO, buf, nbytes) != nbytes)
            {
                perror("Error writing");
                close(fd);
                return -1;
            }
        }

        close(fd);
    }

    return 0;
}
