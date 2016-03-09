#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSZ	1024

int main(int argc, char *argv[])
{
    char      buf[BUFSZ]; //buffer
    int       fd;         //file descriptor
    size_t    nbytes;     //number of bytes read

    int i;
    for( i = 1; i < argc; i++) {

        if( ( fd = open(argv[i], O_RDONLY) ) == -1 ) {
             perror("Could not open file");
    	     exit(1);
        }

        while ( ( nbytes = read(fd, buf, BUFSZ) ) > 0) {

            buf[nbytes] = 0;

            if ( write(STDOUT_FILENO, buf, nbytes) != nbytes) {
                perror("Write error\n\n\n");
                exit(1);
            }
            if ( nbytes < 0 ) {
                perror("Read error\n\n\n");
                exit(1);
            }
        }

    }

    exit(0);
}
