#include "tree.h"

int main(int argc, char *argv[])
{
    char array[] = {'0', '1', '2', '3', '4'};
    BTREE tree = create_tree(array, 0, 5);
    inorder(tree);
    printf("\n");
    return 0;
}
