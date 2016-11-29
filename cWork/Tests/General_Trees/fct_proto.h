#include "gtree.h"

GTREE new_gnode(void);
GTREE init_gnode(DATA d1, int num, GTREE sibs);
void preorder_g(GTREE t, int ind);
void buildtree(PAIR edges[], DATA d[], int n, GTREE t[]);
