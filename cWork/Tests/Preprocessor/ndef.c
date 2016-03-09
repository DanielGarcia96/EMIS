#include <stdio.h>

#ifndef BUGGER_ALL
    #define BUGGER_ALL     "What do you think this would say?"
#endif

int main(void)
{
    printf("%s\n", BUGGER_ALL);
    return 0;
}
