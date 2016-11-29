#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int main(int argc, char *argv[])
{
	Queue queue = newQueue("Doom Queue");
	QElement newElement;
	
	strcpy(newElement.szName, "Zim");
	newElement.iEnterQTime = 0;
	insertQ(queue, newElement);

	strcpy(newElement.szName, "Gir");
	newElement.iEnterQTime = 1;
	insertQ(queue, newElement);

	strcpy(newElement.szName, "Dib");
	newElement.iEnterQTime = 2;
	insertQ(queue, newElement);

	printQueue(queue);

	freeQueue(queue);

	return 0;
}
