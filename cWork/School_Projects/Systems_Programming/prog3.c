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
    for( i = 1; i < argc; i++ ) {

        if( ( fd = open(argv[i], O_RDONLY) ) == -1 ) {
            write(STDERR_FILENO, "Could not open file\n", 20 );
    	    exit(1);
        }

        while ( ( nbytes = read(fd, buf, 1) ) > 0) {

            buf[nbytes] = 0;

            if(*buf == '\n')
                write(STDOUT_FILENO, "\n", 1);

            if ( write(STDOUT_FILENO, buf, nbytes) != nbytes ) {
                write(STDERR_FILENO, "Write error\n", 12);
                exit(1);
            }

            if ( nbytes < 0 ) {
                write(STDERR_FILENO, "Read error\n", 13);
                exit(1);
            }
        }
    }

    exit(0);
}
