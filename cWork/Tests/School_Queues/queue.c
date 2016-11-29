#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void printQName(Queue queue)
{
	printf("%11s\n", queue->szQName);
}

void printQueue(Queue queue)
{
	NodeQ *start = queue->pHead;
	printQName(queue);
	while(queue->pHead != NULL)
	{
		printf("%-10s%d\n", queue->pHead->element.szName, queue->pHead->element.iEnterQTime);
		queue->pHead = (NodeQ *) queue->pHead->pNext;
	}
	queue->pHead = start;
}	

NodeQ *allocateQNode(QElement element)
{
	NodeQ *pNew;
	pNew = (NodeQ *) malloc(sizeof(NodeQ));
	if(pNew == NULL)
	{
		printf("Error, no memory available for allocation\n");
		return NULL;
	}
	pNew->element = element;
	pNew->pNext = NULL;
	return pNew;
}

void insertQ(Queue queue, QElement element)
{
	NodeQ *pNew;
	pNew = allocateQNode(element);
	//check for empty
	if (queue->pFoot == NULL)
	{
		queue->pFoot = pNew;
		queue->pHead = pNew;
	}
	else
	{
		//insert after foot
		queue->pFoot->pNext = (struct NodeQ *) pNew;
		queue->pFoot = pNew;
	}
}

Queue newQueue(char *szQueueNm)
{
	Queue queue = (Queue) malloc(sizeof(QueueImp));
	queue->pHead = NULL;
	queue->pFoot = NULL;
	strcpy(queue->szQName, szQueueNm);
	return queue;
}

void freeQueue(Queue queue)
{
	NodeQ *node = (NodeQ *) queue->pHead;
	while(node->pNext != NULL)
	{
		NodeQ *temp = node;
		node = (NodeQ*) node->pNext;
		free(temp);
	}
	free(node);
	free(queue);
}
