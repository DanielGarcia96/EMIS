#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void printElements(Queue queue)
{
    printf("Printing Elements:\n");

    QNode *start = queue->pHead;
    int count = 0;
    while(queue->pHead != NULL)
    {
        printf("%d ", queue->pHead->bit_map);
        if((count+1) % 4 == 0 && count != 0)
            printf("\n");
        queue->pHead = (QNode *) queue->pHead->pNext;
        ++count;
    }
    printf("\n");

    queue->pHead = start;
}
