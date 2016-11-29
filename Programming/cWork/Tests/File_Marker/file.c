#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 50

int main(int argc, char *argv[])
{
    int a, b, c, d;
    char buffer[BUF];
    FILE *fp = fopen("file.txt", "r");

    fgets(buffer, 50, fp);
    printf("%s", buffer);
    fgets(buffer, 50, fp);
    printf("%s", buffer);
    fgets(buffer, 50, fp);
    printf("%s", buffer);
    fgets(buffer, 50, fp);
    printf("%s", buffer);
    sscanf(buffer,"%d", &a);
    sscanf(buffer,"%d", &b);
    sscanf(buffer,"%d", &c);
    sscanf(buffer,"%d", &d);

    printf("%d %d %d %d\n", a, b, c, d);

    fclose(fp);
    return 0;
}
