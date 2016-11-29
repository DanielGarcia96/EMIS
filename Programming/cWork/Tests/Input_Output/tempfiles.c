#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *tmpfile = tmpnam(NULL);
    FILE *fp = fopen(tmpfile, "w+");
    fprintf(fp, "words");
    fprintf(stdout, "The name of the file is: %s\n", tmpfile);

    fclose(fp);
    remove(tmpfile);
    return 0;
}
