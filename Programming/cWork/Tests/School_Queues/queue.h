#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedefs for the queues

typedef struct
{
    char szName[12];
    int iEnterQTime;
} QElement;

typedef struct
{
    QElement element;
    struct NodeQ *pNext;
} NodeQ;

typedef struct 
{
    NodeQ *pHead;
    NodeQ *pFoot;
    char szQName[12];
} QueueImp;

typedef QueueImp *Queue;

void printQName(Queue queue);
void printQueue(Queue queue);
QElement pop(Queue queue);
void insertQ(Queue queue, QElement element);
NodeQ *allocateQNode(QElement element);
Queue newQueue(char *szQueueNm);
void freeQueue(Queue queue);
