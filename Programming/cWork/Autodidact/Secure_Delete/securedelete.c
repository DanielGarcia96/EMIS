#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#define ERRARG  1
#define ERROPN  2
#define ERRWRT  3
#define ERRFST  3
#define BUF     512

int main(int argc, char *argv[]) {

    if(argc < 2) {
        fprintf(stderr, "Usage: %s filenames[s]\n", argv[0]);
        return ERRARG;
    }

    write(STDOUT_FILENO, "Progress:", 9);

    int i;
    for(i=1; i < argc; i++) {
        char buf[512];
        struct stat st;
        char const *filename = argv[i];
        memset(buf, '\0', BUF);

        int fd;
        if((fd = open(filename, O_WRONLY)) == -1) {
            perror("Error opening file:");
            return ERROPN;
        }

        int fs;
        if((fs = fstat(fd, &st)) == -1) {
            perror("Error statting file:");
            return ERRFST;
        }
        
        ssize_t nbytes;
        off_t cntr = 0;
        
        while((nbytes = write(fd, buf, BUF)) > 0 && cntr <= st.st_size)
            cntr += nbytes;

        close(fd);
        remove(filename);
        write(STDOUT_FILENO, "#", 1);
    }
    write(STDOUT_FILENO, "\n", 1);    

    return 0;
}
