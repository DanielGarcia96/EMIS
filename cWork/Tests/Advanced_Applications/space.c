#include "matrix.h"

matrix get_matrix_space(int m, int n)
{
    int    i;
    elem   *p;
    matrix a;

    p = malloc(m * n * sizeof(elem)); /* get space all at once*/
    a = malloc(m * sizeof(row)
}

void release_matrix_space(matrix a)
{
    elem *p;

    p = (elem *) a[1] + 1;    /* base address of the array */
    free(p);
    free(a + 1);
}
