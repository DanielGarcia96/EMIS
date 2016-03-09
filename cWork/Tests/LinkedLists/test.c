#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void testBasics();
void testIntermediate();
void testAdvanced();

int main(void)
{
    testBasics();
    testIntermediate();
    testAdvanced();

    return 0;
}

void testBasics()
{
    printf("Adding A, B, C, and D\n\n");
    LL list = allocateList('A');
    LLadd(list, 'B');
    LLadd(list, 'C');
    LLadd(list, 'D');


    printf("Printing List\n\n");
    displayList(list);

    printf("\n\n");
    freeList(list);
}

void testIntermediate()
{
    printf("Adding A, B, C, and D\n\n");
    LL list = allocateList('A');
    LLadd(list, 'B');
    LLadd(list, 'C');
    LLadd(list, 'D');

    printf("Printing List\n\n");
    displayList(list);

    printf("Printing index 1\n\n");
    displayNode(list, 1, (char)0);

    printf("Printing index 2\n\n");
    displayNode(list, 2, (char)0);

    printf("Searching and printing C\n\n");
    displayNode(list, -1, 'C');

    printf("Printing index 0\n\n");
    displayNode(list, 0, (char)0);

    printf("Searching and printing A\n\n");
    displayNode(list, -1, 'A');

    printf("Printing index 3\n\n");
    displayNode(list, 3, (char)0);

    printf("Searching and printing D\n\n");
    displayNode(list, -1, 'D');

    freeList(list);
}

void testAdvanced()
{
    printf("Adding A, B, C, and D\n\n");
    LL list = allocateList('A');
    LLadd(list, 'B');
    LLadd(list, 'C');
    LLadd(list, 'D');

    printf("Printing List\n\n");
    displayList(list);

    printf("Inserting a in index 1\n\n");
    LLinsert(list, 1, 'a');

    printf("Inserting b in index 3\n\n");
    LLinsert(list, 3, 'b');

    printf("Printing List\n\n");
    displayList(list);

    printf("Removing index 1\n\n");
    LLremove(list, 1, 'a');

    printf("Removing index 2\n\n");
    LLremove(list, 2, 'b');

    printf("Printing List\n\n");
    displayList(list);

    printf("Inserting a in index 0\n\n");
    LLinsert(list, 0, 'a');

    printf("Inserting c in index 4\n\n");
    LLinsert(list, 4, 'd');

    printf("Printing List\n\n");
    displayList(list);

    printf("\n\n");
    freeList(list);
}
