typedef    char    DATA;

struct node {
    DATA            d;
    struct node     *left;
    struct node     *right;
};

typedef    struct node    NODE;
typedef    NODE           *BTREE;

BTREE new_node(void);
BTREE init_node(DATA d1, BTREE p1, BTREE p2);
BTREE create_tree(DATA a[], int i, int size);
void inorder(BTREE root);
void preorder(BTREE root);
void postorder(BTREE root);
