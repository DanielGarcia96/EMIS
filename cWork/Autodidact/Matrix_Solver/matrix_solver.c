#include "fmatrix.h"
int main(int argc, char **argv)
{
    if(argc < 2)
    {
        fprintf(stderr, "Usage: %s <matrix-file>\n", argv[0]);
        return -1;
    }

    FILE *fp;
    if((fp = fopen(argv[1], "r")) == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    int r1 = 0, c1 = 0, r2 = 0, c2 = 0, flag1 = 1, *tmp_r, *tmp_c, **tmp_m,
        **m1 = (int **) malloc(50*sizeof(int *)),
        **m2 = (int **) malloc(50*sizeof(int *));

    int i;
    for(i=0; i<50; i++)
    {
        m1[i] = (int *) malloc(50*sizeof(int));
        m2[i] = (int *) malloc(50*sizeof(int));
    }

    char buffer[1024];
    char *token = (char *) malloc(1024*sizeof(char));
    while(fgets(buffer, 1024, fp) != NULL)
    {
        if(strcmp(buffer, "\n") == 0)
        {
            flag1 = 0;
            continue;
        }

        tmp_c = (flag1 ? &c1 : &c2);
        *tmp_c = 0;
        tmp_r = (flag1 ? &r1 : &r2);
        *tmp_r += 1;
        token = strtok(buffer, " ");

        while(token != NULL)
        {
            if(strcmp(token, "\n") == 0 || 
               strcmp(token, "") == 0 ||
               strcmp(token, " ") == 0)
            {
                token = strtok(NULL, " ");
                continue;
            }

            tmp_m = (flag1 ? m1 : m2);
            tmp_m[(*tmp_r)-1][(*tmp_c)] = atoi(token);
            token = strtok(NULL, " ");
            tmp_c = (flag1 ? &c1 : &c2);
            *tmp_c += 1;
        }
    }


    printMatrix(m1, r1, c1);
    printMatrix(m2, r2, c2);
    printMatrix(addition(m1, m2, r1, c1), r1, c2);

    for(i=0; i<50; i++)
    {
        free(m1[i]);
        free(m2[i]);
    }

    free(m1);
    free(m2);
    fclose(fp);
    return 0;
}
