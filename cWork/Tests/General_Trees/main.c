#include "fct_proto.h"

int main(int argc, char *argv[])
{
    DATA data = 'a';
    GTREE sibs = new_gnode();
    GTREE tree = init_gnode(data, 0, sibs);
    return 0;
}
