#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef    char    DATA;

struct node {
    int          child_no;
    DATA         d;
    struct node  *sib;
};

typedef struct {
    int    out;
    int    in;
} PAIR;

typedef    struct node    NODE;
typedef    NODE           *GTREE;
