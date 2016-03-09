#include <stdio.h>

#define SQU(x)    (x) * (x)
#define min(x, y) (((x) < (y)) ? (x) : (y))
#define max(x, y) (((x) > (y)) ? (x) : (y))

int main(int argc, char *argv[])
{
    printf("4 squared is %d\n", SQU(4));
    printf("5 plus 5 squared is %d\n", SQU(5+5));
    printf("Which is smaller, 23+15 or 16+19?\n");
    printf("Answer: %d\n", min(23+15, 16+19));
    printf("Which is bigger, 45+52 or 37+63?\n");
    printf("Answer: %d\n", max(45+52, 37+63));
    return 0;
}
