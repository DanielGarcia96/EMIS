#include <stdio.h>

int fork(void);

int main(int argc, char *argv[])
{
    int i;

    for(i = 0; i < 2; i++)
        printf("%d\n", fork());

    return 0;
}
