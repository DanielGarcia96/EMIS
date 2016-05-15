#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int    fork(void), value;

    int i;
    for ( i = 0; i < 4; i++ )
    {
        value = fork();                        /* new process */

        pid_t tp = getpid();
        printf("This process = %d\n", tp);

        value = fork();                        /* new process */
        value = fork();                        /* new process */
    
        printf("In main: value = %d\n", value);
    }
    return 0;
}
