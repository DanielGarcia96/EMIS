#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char *argv[] = {"-l", NULL};
    execvp("ls", argv);
    return 0;
}
