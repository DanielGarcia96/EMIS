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
    printf("Testing Basics\n\n");

    printf("Adding A, B, C, and D\n");
    LL list = allocateList('A');
    LLadd(list, 'B');
    LLadd(list, 'C');
    LLadd(list, 'D');


    printf("Printing List\n");
    displayList(list);

    freeList(list);
}

void testIntermediate()
{
    printf("\n\nTesting Intermediate\n\n");

    printf("Adding A, B, C, and D\n");
    LL list = allocateList('A');
    LLadd(list, 'B');
    LLadd(list, 'C');
    LLadd(list, 'D');

    printf("Printing List\n");
    displayList(list);

    printf("\nPrinting index 1\n");
    displayNode(list, 1, (char)0);

    printf("\nPrinting index 2\n");
    displayNode(list, 2, (char)0);

    printf("\nSearching and printing C\n");
    displayNode(list, -1, 'C');

    printf("\nPrinting index 0\n");
    displayNode(list, 0, (char)0);

    printf("\nSearching and printing A\n");
    displayNode(list, -1, 'A');

    printf("\nPrinting index 3\n");
    displayNode(list, 3, (char)0);

    printf("\nSearching and printing D\n");
    displayNode(list, -1, 'D');

    freeList(list);
}

void testAdvanced()
{
    printf("\n\nTesting Advanced\n\n");

    printf("Adding A, B, C, and D\n");
    LL list = allocateList('A');
    LLadd(list, 'B');
    LLadd(list, 'C');
    LLadd(list, 'D');

    printf("Printing List\n");
    displayList(list);

    printf("\nInserting a in index 1\n");
    LLinsert(list, 1, 'a');

    printf("Inserting b in index 3\n\n");
    LLinsert(list, 3, 'b');

    printf("Printing List\n");
    displayList(list);

    printf("\nRemoving index 1\n");
    LLremove(list, 1, 'a');

    printf("Removing index 2\n\n");
    LLremove(list, 2, 'b');

    printf("Printing List\n");
    displayList(list);

    printf("\nInserting a in index 0\n");
    LLinsert(list, 0, 'a');

    printf("Inserting c in index 4\n");
    LLinsert(list, 4, 'd');

    printf("\nPrinting List\n");
    displayList(list);

    freeList(list);
}
