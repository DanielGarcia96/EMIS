#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMatrix(int **m, int r, int c)
{
    printf("Rows: %d\nColumns: %d\n", r, c);
    int i, j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
    printf("\n");
}

int determinant_2(int **m)
{
    return (m[0][0]*m[1][1]) - (m[0][1]*m[1][0]);
}

int determinant_3(int **m)
{
    return ((m[0][0]*((m[1][1]*m[2][2])-(m[1][2]*m[2][1]))) -
            (m[0][1]*((m[1][0]*m[2][2])-(m[1][2]*m[2][0]))) +
            (m[0][2]*((m[1][0]*m[2][1])-(m[1][1]*m[2][0])))) ;
}

int determinant_g(int **m, int r, int c)
{
    printMatrix(m, r, c);
    if(r == 2 && c == 2)
        return determinant_2(m);
    else if(r == 3 && c == 3)
        return determinant_3(m);

    int i, j, k, mflag = 0, dtrmnt = 0;
    for(i=0; i<c; i++)
    {
        int **tmp = (int **) malloc((r-1)*sizeof(int *));
        if(tmp == NULL)
        {
           perror("Malloc error");
           exit(-1);
        }
        printf("Mallocing\n");
        for(j=0; j<(r-1); j++)
            tmp[j] = (int *) malloc((c-1)*sizeof(int));

        int tr = 0, tc = 0;
        for(j=1; j<r; j++)
        {
            for(k=0; k<c; k++)
            {
                if(k==i){ continue; }
                tmp[tr][tc] = m[j][k];
                tc++;
            }
            tr++;
            tc = 0;
        }

        int returnDtr = (m[0][i])*determinant_g(tmp, r-1, c-1);
        printf("returnDtr: %d\n", returnDtr);
        if(mflag)
            dtrmnt -= returnDtr;
        else
            dtrmnt += returnDtr;

        for(j=0; j<(r-1); j++)
            free(tmp[j]);

        free(tmp);
        mflag = !mflag;
    }
    return dtrmnt;
}

int **addition(int **m1, int **m2, int r, int c)
{
    int i, j;
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            m1[i][j] += m2[i][j];
    return m1;
} 
