#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "bit_include.h"

int main(int argc, char *argv[])
{
    Queue queue = allocateQueue(0);

    addElement(queue, 1);
    addElement(queue, 2);
    addElement(queue, 3);
    addElement(queue, 4);
    addElement(queue, 5);
    addElement(queue, 6);
    addElement(queue, 7);
    addElement(queue, 8);
    addElement(queue, 9);
    addElement(queue, 10);

    printElements(queue);

    printf("What I just popped was :\n");
    bit_print(pop(queue));

    printf("What I just popped was :\n");
    bit_print(pop(queue));

    printf("What I just popped was :\n");
    bit_print(pop(queue));

    freeQueue(queue);
    return 0;
}
