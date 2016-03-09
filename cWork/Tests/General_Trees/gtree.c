#include "fct_proto.h"

GTREE new_gnode(void)
{
    return (malloc(sizeof(NODE)));
}

GTREE init_gnode(DATA d1, int num, GTREE sibs)
{
    GTREE    tmp;
    
    tmp = new_gnode();
    tmp -> d = d1;
    tmp -> child_no = num;
    tmp -> sib = sibs;
    return tmp;
}

void preorder_g(GTREE t, int ind)
{
    GTREE tmp;     /* tmp traverses the sibling list */

    tmp = t[ind];  /* t[ind] is the root node */
    while (tmp != NULL) {
        printf("%c  %d\n", tmp -> d, tmp -> child_no);
        preorder_g(t, tmp -> child_no);
        tmp = tmp -> sib;
    }
}

void buildtree(PAIR edges[], DATA d[], int n, GTREE t[])
{
    int i;
    int x, y;                           /* points of edge */

    t[0] = init_gnode(d[1], 1, NULL);
                               /* t[0] takes node 1 as root */
    for (i = 1; i <= n; ++i)
        t[i] = NULL;
    for (i = 0; i < n - 1; ++i) {
        x = edges[i].out;
        y = edges[i].in;
        t[x] = init_gnode(d[y], y, t[x]);
    }
}
