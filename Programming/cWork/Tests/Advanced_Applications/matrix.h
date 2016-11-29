#include <stdio.h>
#include <stlib.h>

typedef    double **   matrix;
typedef    double *    row;
typedef    double      elem;

matrix     get_matrix_space(int m, int n);
void       release_matrix_space(matrix a);
void       fill_matrix(matrix a, int m, int n);
void       prn_matrix(const char *s, matrix a, int m, int n);
