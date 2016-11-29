#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUF 1024

void printString(char string[], size_t nbytes, int fd);
int doubleSpace(char *string1, char *string2);

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
            printString(buf, nbytes, fd);

        close(fd);
    }
    return 0;
}

void printString(char string[], size_t nbytes, int fd)
{
    char result[nbytes*2];
    memset(result, '\0', sizeof(result));
    size_t str_idx = 0, res_idx = 0, nlcnt = 0;
    while(str_idx < nbytes)
    {
        result[res_idx] = string[str_idx];
        if(string[str_idx] == '\n')
        {
            printf("Encountered newline at line %d\n", str_idx);
            res_idx++;
            result[res_idx] = '\n';
            nlcnt++;
        }
        res_idx++;
        str_idx++;
    }

    if(write(STDOUT_FILENO, string, nbytes+nlcnt) != nbytes+nlcnt)
    {
        perror("Writing error");
        close(fd);
        exit(-1);
    }
}
