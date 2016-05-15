#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF 1024

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "usage: %s <infile>\n", argv[0]);
        return -1;
    }

    int fd;
    char buf[BUF];

    if((fd = open(argv[1], O_RDONLY)) == -1)
    {
        perror("Error opening file");
        return -1;
    }
    
    size_t nbytes;
    while((nbytes = read(fd, buf, BUF)) > 0)
    {
        if(write(STDOUT_FILENO, buf, nbytes) != nbytes)
        {
            perror("Writing error");
            close(fd);
            return -1;
        }
    }
   
    close(fd);
    return 0;
}
