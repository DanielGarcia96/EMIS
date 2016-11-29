#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "cs2123p6.h"

/************************computePertTEAndTL**************************
void computePertTEAndTL(Graph graph)
Purpose: Finds and modifies the values of TE and TL within Graph Vertices
Parameters:
	I/O	Graph graph	Graph that is being read from and having
				its vertices modified
Notes:
	-Seg faults with a NULL Graph
********************************************************************/
void computePertTEAndTL(Graph graph)
{ 	
	Vertex sourceVerticesM[MAX_SOURCES];
	Vertex sinkVerticesM[MAX_SINKS];
	int iSourceCnt = 0;
	int iSinkCnt = 0;

	findSinksAndSources(graph, sinkVerticesM, sourceVerticesM, &iSourceCnt, &iSinkCnt);

	int i;

	for(i = 0; i < iSourceCnt; i++)
		computePertTE(graph, &(sourceVerticesM[i]));
	
	for(i = 0; i< iSinkCnt; i++)
		findDistFromSinks(graph, &(sinkVerticesM[i]));

	int iMaxTE = findMaxTE(graph);
	computePertTL(graph, iMaxTE); 
}

/************************computePertTE**************************
void computePertTE(Graph graph, Vertex *vertex)
Purpose: Recursively loops through a Graph's Vertices and modifies
	 their longest distance from the a source
Parameters:
	I/O	Graph graph	Graph that is being read from and having
				its vertices modified
Notes:
	-Vertex pointer must be a source
**************************************************/
void computePertTE(Graph graph, Vertex *vertex)
{
	if(vertex->successorList == NULL)
	{
		vertex->iMaxFromSource = findHighestPath(graph, vertex->predecessorList, 'O');
		return;
	}

	vertex->iMaxFromSource = findHighestPath(graph, vertex->predecessorList, 'O'); 

	EdgeNode *startNode = vertex->successorList;
	while(startNode != NULL)
	{
		computePertTE(graph, &(graph->vertexM[startNode->edge.iVertex]));
		startNode = startNode->pNextEdge;
	}
}

/************************computePertTL**************************
void computePertTL(Graph graph, int iMaxTE)
Purpose: Recursively loops through a Graph's Vertices and modifies
	 their TL value
Parameters:
	I/O	Graph graph	Graph that is being read from and having
				its vertices modified 
	I	int iMaxTE	Maximum distance a Vertex has from a source
Notes:
**************************************************/
void computePertTL(Graph graph, int iMaxTE)
{
	int i;
	for(i = 0; i < graph->iNumVertices; i++)
	{
		graph->vertexM[i].iTL = iMaxTE - graph->vertexM[i].iMaxFromSink;
	}
}

/************************printCriticalPaths**************************
void printCriticalPaths(Graph graph)
Purpose: Prints the critical path(s) for a Graph
Parameters:
	I	Graph graph	Graph that is being read from
Notes:
	-If there are no critical paths nothing is printed
********************************************************************/
void printCriticalPaths(Graph graph)
{
	printf("Critical Path(s)\n");

	char szPathNodes[MAX_VERTICES];

	int i;
	for(i = 0; i < graph->iNumVertices; i++)
	{
		memset(szPathNodes, 0, sizeof(szPathNodes));
		if(graph->vertexM[i].predecessorList == NULL)
		{
			determinePath(graph, graph->vertexM[i], szPathNodes);
			szPathNodes[strlen(szPathNodes)] = '\0';

			if(szPathNodes[0] != '\0')
				printf("%s\n", szPathNodes);
		}
	}
}

/************************determinePath**************************
void determinePath(Graph graph, Vertex vertex, char szPathNodes[])
Purpose: Recursively traces through Graph and finds all critical nodes
Parameters:
	I	Graph graph		Graph that is being read from
	I	Vertex vertex		Vertex that is being currently being
					read
	O	char szPathNodes	Char string of collected critical nodes
Notes:
	-The first Vertex must be a source
***************************************************************/
void determinePath(Graph graph, Vertex vertex, char szPathNodes[])
{
	if(vertex.successorList == NULL)
	{
		strcat(szPathNodes, &vertex.cLabel);
		strcat(szPathNodes, " ");
		return;
	}
	
	if(vertex.iMaxFromSource == vertex.iTL)
	{
		strcat(szPathNodes, &vertex.cLabel);
		strcat(szPathNodes, " ");
	}
	
	if(vertex.iMaxFromSource != vertex.iTL)
	{
		return;
	}

	EdgeNode *startNode = vertex.successorList;
	while(startNode != NULL)
	{
		determinePath(graph, graph->vertexM[startNode->edge.iVertex], szPathNodes);
		startNode = startNode->pNextEdge;
	}
}

/************************freeGraph**************************
void freeGraph(Graph graph)
Purpose: Frees all memory associated with a Graph
Parameters:
	I/O	Graph graph	Graph that is being read from and having
				its vertices modified
Notes:
************************(**********************************/
void freeGraph(Graph graph)
{
	int i;
	for(i = 0; i < graph->iNumVertices; i++)
	{
		freeLL(graph->vertexM[i].successorList);
		freeLL(graph->vertexM[i].predecessorList);
	}

	free(graph);
}

/************************freeLL**************************
void freeLL(EdgeNode *root)
Purpose: Frees a linked list data structure
Parameters:
	I/O	EdgeNode *root	First node in the linked
				list that all the others
				are freed from
Notes:
	-This assumes that the list has been handled
	 properly and memory has not been lost before the
	 function executes
********************************************************/
void freeLL(EdgeNode *root)
{
	EdgeNode *node;
	while(root != NULL)
	{
		node = root;
		root = root->pNextEdge;
		free(node);
	}
}

/************************findHighestPath**************************
int findHighestPath(Graph graph, EdgeNode *list, char cType)
Purpose: Multi-purpose function that returns the highest distance
	 from either a source or a sink to a given vertex
Parameters:
	I	Graph graph		Graph that is being read from
	I	EdgeNodes  *list	List of either successors or
					predecessors that surround a
					given vertex
	I	char cType		Char that determines whether
					the distance from a source or
					sink is being found
Returns:
	-returns an of the max distance from either a source or
	 sink
Notes:
**************************************************/
int findHighestPath(Graph graph, EdgeNode *list, char cType)
{
	EdgeNode *startNode = list;
	int iHighestPath = 0;
	while(startNode != NULL)
	{
		if(cType == 'O')
		{
			if(startNode->edge.iPath + graph->vertexM[startNode->edge.iVertex].iMaxFromSource > iHighestPath)
				iHighestPath = startNode->edge.iPath + graph->vertexM[startNode->edge.iVertex].iMaxFromSource;

			startNode = startNode->pNextEdge;
		}
		else
		{
			if(startNode->edge.iPath + graph->vertexM[startNode->edge.iVertex].iMaxFromSink > iHighestPath)
				iHighestPath = startNode->edge.iPath + graph->vertexM[startNode->edge.iVertex].iMaxFromSink;

			startNode = startNode->pNextEdge;

		}
	}
	return iHighestPath;
}

/************************findSinksAndSources**************************
void findSinksAndSources(Graph graph, Vertex sinkVerticesM[], Vertex sourceVerticesM[], int *iSourceCnt, int *iSinkCnt)
Purpose: Finds all the sinks and sources within a Graph
Parameters:
	I	Graph graph			Graph that is being read from
	O	Vertex sinkVerticesM[]		Array of sink Vertices that are being returned
	O	Vertex sourceVerticesM[]	Array of source Vertices that are being returned
	O	int *iSourceCnt			int pointer count of source vertices
	O	int *iSinkCnt			int pointer count of sink vertices
Notes:
*********************************************************************/
void findSinksAndSources(Graph graph, Vertex sinkVerticesM[], Vertex sourceVerticesM[], int *iSourceCnt, int *iSinkCnt)
{
	int i;
	for(i = 0; i < graph->iNumVertices; i++)
	{
		if(graph->vertexM[i].predecessorList == NULL)
		{
			sourceVerticesM[*iSourceCnt] = graph->vertexM[i];
			*iSourceCnt += 1;
		}
		else if(graph->vertexM[i].successorList == NULL)
		{
			sinkVerticesM[*iSinkCnt] = graph->vertexM[i];
			*iSinkCnt += 1;
		}
	}
} 
/************************findDistFromSinks**************************
void findDistFromSinks(Graph graph, Vertex *vertex)
Purpose: Finds that max distance from a sink for all the Vertices in a Graph
Parameters:
	I/O	Graph graph 	Graph that is being read from and having its
				vertices modified
	I/O	Vertex *vertex	Vertex pointer that is currently being read and
				modified
Notes:
**************************************************/
void findDistFromSinks(Graph graph, Vertex *vertex)
{
	if(vertex->predecessorList == NULL)
	{
		vertex->iMaxFromSink = findHighestPath(graph, vertex->successorList, 'I');
		return;
	}

	vertex->iMaxFromSink = findHighestPath(graph, vertex->successorList, 'I'); 

	EdgeNode *startNode = vertex->predecessorList;
	while(startNode != NULL)
	{
		findDistFromSinks(graph, &(graph->vertexM[startNode->edge.iVertex]));
		startNode = startNode->pNextEdge;
	}
}

/************************findMaxTE**************************
int findMaxTE(Graph graph)
Purpose: Loops through a Graph's vertices and returns the
	 highest distance from a source
Parameters:
	I	Graph graph	Graph that is being read from
Returns:
	-Highest distance from a source out of all Vertices
Notes:
	-Seg faults if graph is NULL
**************************************************/
int findMaxTE(Graph graph)
{
	int iMaxTE = 0;
	
	int i;
	for(i = 0; i<graph->iNumVertices; i++)
	{
		if(graph->vertexM[i].iMaxFromSource > iMaxTE)
			iMaxTE = graph->vertexM[i].iMaxFromSource;
	}

	return iMaxTE;
}
