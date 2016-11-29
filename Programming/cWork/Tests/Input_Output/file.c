#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *printfile = fopen("testfile", "w+");
    fprintf(printfile, "This is a line in a file");

    fclose(printfile);

    int a,b,c;
    FILE *datafile = fopen("datafile", "r");
    fscanf(datafile, "%d %d %d", &a, &b, &c);

    fprintf(stdout, "The sum of %d, %d, and %d is %d\n", a, b, c, a+b+c);

    fclose(datafile);
    return 0;
}
