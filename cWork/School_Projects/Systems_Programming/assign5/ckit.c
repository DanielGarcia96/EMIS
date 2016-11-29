#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define    BUF    1024

size_t openFiles(int argc, char *argv[], char stdbuf[BUF], 
int *fd1, int *fd2, int *fd3);

void printFiles(int argc, char *argv[], char stdbuf[BUF], 
size_t stdread, int *fd1, int *fd2, int *fd3);

int main(int argc, char *argv[])
{
    char   stdbuf[BUF];     //buffer for stdin
    int    fd1, fd2, fd3;   //file descriptors for various files

    size_t stdread = openFiles(argc, argv, stdbuf, &fd1, &fd2, &fd3);
    printFiles(argc, argv, stdbuf, stdread, &fd1, &fd2, &fd3);

    close(fd1);
    close(fd2);
    close(fd3);
    exit(0);
}


size_t openFiles(int argc, char *argv[], char stdbuf[], 
int *fd1, int *fd2, int *fd3)
{
    short unsigned bSTD = 0;
    size_t nbytes = 0;

    if ( argc < 2 ) {
        perror("Usage: ");
        perror(argv[0]);
        perror(" <file1> <file2> [outfile]\n");
        exit(1);
    }

    if ( *argv[1] != '-') {
        if ( ( *fd1 = open(argv[1], O_RDONLY) ) == -1 ) {
            printf("Error occured at %d\n", __LINE__ - 1);
            perror("Error opening ");
            perror(argv[1]);
            perror("\n");
            close(*fd1);
            exit(1);
        }
    }
    else {
        while ( ( nbytes != read(STDIN_FILENO, stdbuf, BUF) ) > 0 );
    }

    if ( *argv[2] != '-') {
        if ( ( *fd2 = open(argv[2], O_RDONLY) ) == -1 ) {
            printf("Error occured at %d\n", __LINE__ - 1);
            perror("Error opening ");
            perror(argv[2]);
            perror("\n");
            close(*fd2);
            exit(1);
        }
    }
    else {
        if(bSTD) {
            printf("Error, stdin read in twice\n");
            close(*fd1);
            exit(1);
        }
        else {
            while ( ( nbytes != read(STDIN_FILENO, stdbuf, BUF) ) > 0 );
        }
    }

    if ( argc == 4 ) {
        if (  ( *fd3 = open(argv[3], O_WRONLY | O_CREAT) ) == -1 ) {
            printf("Error occured at %d\n", __LINE__ - 1);
            perror("Error opening ");
            perror(argv[3]);
            perror("\n");
            close(*fd3);
            exit(1);
        }
    }
    else {
        *fd3 = STDOUT_FILENO;
    }

    return nbytes;
}

void printFiles(int argc, char *argv[], char stdbuf[BUF], 
size_t stdread, int *fd1, int *fd2, int *fd3)
{
    char   filebuf[BUF];    //buffer for reading the file
    size_t nbytes = 0;      //number of bytes read

    if(*argv[1] == '-') {
        if(argc == 4) {
            if ( write(*fd3, stdbuf, stdread) < 0) {
               perror("Error writing\n");
               close(*fd1);
               close(*fd2);
               close(*fd3);
               exit(1);
            }
        }
        else {
            if ( write(STDOUT_FILENO, stdbuf, stdread) < 0) {
               perror("Error writing\n");
               close(*fd1);
               close(*fd2);
               close(*fd3);
               exit(1);
            }
        }
    }
    else {
        while( ( nbytes = read(*fd1, filebuf, BUF) ) > 0 ) {
            if ( write(*fd3, filebuf, nbytes) < 0 ) {
                printf("Error occured at %d\n", __LINE__ - 1);
                perror("Error writing \n");
                close(*fd1);
                close(*fd2);
                close(*fd3);
                exit(1);           
            }
        }
    }

    if(*argv[2] == '-') {
        if(argc == 4) {
            if ( write(*fd3, stdbuf, stdread) < 0) {
               perror("Error writing\n");
               close(*fd1);
               close(*fd2);
               close(*fd3);
               exit(1);
            }
        }
        else {
            if ( write(STDOUT_FILENO, stdbuf, stdread) < 0) {
               perror("Error writing\n");
               close(*fd1);
               close(*fd2);
               close(*fd3);
               exit(1);
            }
        }
    }
    else {
        while( ( nbytes = read(*fd2, filebuf, BUF) ) > 0 ) {
            if ( write(*fd3, filebuf, nbytes) < 0 ) {
                printf("Error occured at %d\n", __LINE__ - 1);
                perror("Error writing \n");
                close(*fd1);
                close(*fd2);
                close(*fd3);
                exit(1);           
            }
        }
    }
}
