#include "ecrypt.h"

int encrypt(int fd, int cipher)
{
    char buffer[BUF];
    size_t nbytes, position = 0;
    while((nbytes = read(fd, buffer, BUF)) > 0)
    {
        position += nbytes;
        if(lseek(fd, position-nbytes, SEEK_SET) < 0)
        {
            perror("Error positioning");
            close(fd);
            return -1;
        }

        e_alg(cipher, buffer);
        if(write(fd, buffer, nbytes) < 0)
        {
            perror("Error writing");
            close(fd);
            return -1;
        }
    }
    return 0;
}

void e_alg(int cipher, char buffer[])
{
    int i;
    for(i=0; i<strlen(buffer); i++)
        buffer[i] = (cipher%128) + (int)buffer[i];
}

int decrypt(int fd, int cipher)
{
    char buffer[BUF];
    size_t nbytes, position = 0;
    while((nbytes = read(fd, buffer, BUF)) > 0)
    {
        position += nbytes;
        if(lseek(fd, position-nbytes, SEEK_SET) < 0)
        {
            perror("Error positioning");
            close(fd);
            return -1;
        }

        d_alg(cipher, buffer);
        if(write(fd, buffer, nbytes) < 0)
        {
            perror("Error writing");
            close(fd);
            return -1;
        }
    }
    return 0;
}

void d_alg(int cipher, char buffer[])
{
    int i;
    for(i=0; i<strlen(buffer); i++)
        buffer[i] = (int)buffer[i] - (cipher%128);
}
