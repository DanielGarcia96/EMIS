#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int a, b, c, d;
    char buffer[50];
    FILE *fp = fopen("file.txt", "r");

    fgets(buffer, 50, fp);
    sscanf(buffer,"%d", &a);
    fgets(buffer, 50, fp);
    sscanf(buffer,"%d", &b);
    fgets(buffer, 50, fp);
    sscanf(buffer,"%d", &c);
    fgets(buffer, 50, fp);
    sscanf(buffer,"%d", &d);

    printf("%d %d %d %d\n", a, b, c, d);

    fclose(fp);
    return 0;
}
