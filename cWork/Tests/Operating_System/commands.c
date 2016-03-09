#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    system("touch testfile");
    system("echo testfile made");
    system("ls");
    return 0;
}
