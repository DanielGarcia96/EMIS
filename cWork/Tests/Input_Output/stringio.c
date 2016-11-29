#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int a,b,c;
    char *string = "18 21 19";
    
    sscanf(string, "%d %d %d", &a, &b, &c);
    printf("The sum of %d, %d, and %d is %d\n", a, b, c, a+b+c);

    return 0;
}
