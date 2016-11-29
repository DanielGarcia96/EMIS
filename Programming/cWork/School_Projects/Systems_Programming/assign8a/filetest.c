#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(void)
{
    int fd = open("somefile", O_WRONLY | O_APPEND | O_CREAT, S_IROTH | S_IRGRP | S_IWGRP | S_IRUSR | S_IWUSR);
    write(fd, "\nThis is some output\n", strlen("This is some output")+2);
    close(fd);
    return 0;
}
