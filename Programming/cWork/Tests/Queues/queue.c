#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue allocateQueue(int new_bit)
{
    Queue queue = (Queue) malloc(sizeof(Queue));
    queue->pHead = (QNode *) malloc(sizeof(QNode));
    queue->pHead->pNext = NULL;
    queue->pHead->bit_map = new_bit;
    queue->iCount = 0;
    queue->iStartIdx = 0;
    return queue;
}

void addElement(Queue queue, int new_bit)
{
    QNode *start = queue->pHead;
    while(queue->pHead->pNext != NULL)
       queue->pHead = (QNode *) queue->pHead->pNext;
         
    queue->pHead->pNext = (struct QNode *) malloc(sizeof(QNode));
    queue->pHead = (QNode *) queue->pHead->pNext;
    queue->pHead->bit_map = new_bit;
    queue->pHead->pNext = NULL;
    queue->pHead = start;

    queue->iCount += 1;
}

int pop(Queue queue)
{
    QNode *temp = queue->pHead;

    int return_bit = queue->pHead->bit_map;
    if(queue->pHead->pNext != NULL)
        queue->pHead = (QNode *) queue->pHead->pNext;
    free(temp);
    return return_bit;
}

void freeQueue(Queue queue)
{
    while(queue->pHead != NULL)
    {
        QNode *tmp = queue->pHead;
        queue->pHead = (QNode *) queue->pHead->pNext;
        free(tmp);
    }

    free(queue);
}
