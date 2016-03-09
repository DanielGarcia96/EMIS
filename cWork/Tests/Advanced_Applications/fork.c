#include <stdio.h>

int main(int argc, char *argv[])
{
    int    fork(void), value;

    value = fork();                        /* new process */
    value = fork();                        /* new process */
    printf("In main: value = %d\n", value);
    return 0;
}
