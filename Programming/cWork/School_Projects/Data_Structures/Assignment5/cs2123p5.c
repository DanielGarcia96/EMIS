#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs2123p5.h"

/************************prettyPrintT**************************
void prettyPrintT(NodeT *p, int iIndent, TextList textList)
Purpose: Displays the contents of a binary tree in an ordered fashion
Parameters: 
	I	NodeT *p		Root of binary tree that is being
					displayed
	I	int iIndent		Indention for each node in the tree
	I	TextList textList	TextList from which information on
					the node is retrieved
**************************************************************/
void prettyPrintT(NodeT *p, int iIndent, TextList textList)
{
	int i;

	if (p == NULL)
		return;

	prettyPrintT(p->pRight, iIndent+1, textList);
	printf("\n");

	for(i=0; i<iIndent; i++)
	{
		printf("    ");
	}

	if(p != NULL)
		printNode(p, textList);

	printf("\n");
	prettyPrintT(p->pLeft, iIndent+1, textList);
}

/************************printNode**************************
void printNode(NodeT *p, TextList textList)
Purpose: Displays the szId and szText of a NodeT
Parameters:
	I	NodeT *p		Node to be displayed
	I	TextList textList	TextList that is read from
Notes:
	-Will print warning statement and continue executing
	 if the searched for ID is not found in the TextList
***********************************************************/
void printNode(NodeT *p, TextList textList)
{
	int i, bFound = FALSE;

	for(i=0; i<textList->iNumEntry; i++)
	{
		if(strcmp(p->element.szId, textList->arrayM[i].szId) == 0)
		{
			bFound = TRUE;
			break;
		}
	}
	
	if(bFound)	
		printf("%s: %s", textList->arrayM[i].szId, textList->arrayM[i].szText);
}

/************************freeT**************************
void freeT(NodeT *p)
Purpose: Frees a node and all of its descendents
Parameters:
	I	NodeT *p	Parent node that is to have
				its descendents and itself
				freed
Notes:
*******************************************************/
void freeT(NodeT *p)
{
	if(p == NULL)
		return;

	freeT(p->pRight);
	p->pRight = NULL;

	freeT(p->pLeft);
	p->pLeft = NULL;

	free(p);
	p = NULL;
}

/************************searchT**************************
NodeT * searchT(NodeT *p, char szId[])
Purpose: Finds a NodeT that is reffered to by ID
Parameters:
	I/O	NodeT *p	Root of the binary tree
				from which search is being
				executed
	I	char szId[]	ID that is being searched for
Notes:
	-returns NULL if NodeT is not found
*********************************************************/
NodeT * searchT(NodeT *p, char szId[])
{
	NodeT *pwk;
	
	if(p == NULL) 
		return NULL;
	if(strcmp(p->element.szId, szId) == 0)
		return p;
	if((pwk=searchT(p->pRight,szId))!=NULL)
		return pwk;
	if((pwk=searchT(p->pLeft,szId))!=NULL)
		return pwk;
		
	return NULL;
}

/************************allocateNodeT**************************
NodeT * allocateNodeT(Element elem)
Purpose: Allocates memory for a new NodeT pointer
Parameters:
	I/O	Element elem	Element that is to fill the newly
				allocated NodeT
***************************************************************/
NodeT * allocateNodeT(Element elem)
{
	NodeT *pNew = (NodeT *) malloc(sizeof(NodeT));
	pNew->element = elem;
	pNew->pLeft = NULL;
	pNew->pRight = NULL;
	return pNew;
}

/************************insertT**************************
void insertT(NodeT *p, Element element, char szParentId[], char cYN)
Purpose: Allocates and inserts a NodeT in a specified place in the
	 binary tree.
Parameters:
	I	NodeT *p		Root of binary that search is run in
	I	Element element		Element that is to be filling the newly
					allocated Node
	I	char szParentId[]	Parent of chosen for insertion under
Notes:
	-If there is any child nodes are already under the specified
	 parent node, then they will be not replaced
*********************************************************/
void insertT(NodeT *p, Element element, char szParentId[], char cYN)
{
	NodeT *pStart = p;
	NodeT *pParent = searchT(p, szParentId);
	p = pStart;

	if(pParent == NULL)
	{
		printf("\t*** Warning:  Parent ID not found\n");
		return;
	}

	if(cYN == 'Y')
	{
		if(pParent->pRight == NULL)
			pParent->pRight = allocateNodeT(element);
		else
			printf("\t*** Warning:  Child node already occupied\n");
	}
	else
	{
		if(pParent->pLeft == NULL)
			pParent->pLeft = allocateNodeT(element);
		else
			printf("\t*** Warning:  Child node already occupied\n");
	}
}

/************************help**************************
char * help(NodeT *p, char szAnswers[], int iAns, TextList textList)
Purpose: Traverse binary tree based on answers to each question node
Parameters:
	I	NodeT *p		Root of binary tree where help
					execution starts
	I	char szAnswers[]	String of answers to question nodes
	O	int iAns		Number of answers
	I/O	TextList textList	TextList read from
Notes:
**************************************************/
char * help(NodeT *p, char szAnswers[], int iAns, TextList textList)
{
	NodeT *pStart = p;
	while(p != NULL)
	{
		if(p->element.cNodeType == 'D')
			break;

		if(p == NULL)
			printf("IS NULL\n");
		else
			printf("NOT NULL\n");

		if(*szAnswers == 'Y')
		{
			printf("%s: %s %c\n", p->element.szId, getText(textList, p->element.szId), *szAnswers);
			p = p->pRight;
			szAnswers++;
		}
		else
		{
			printf("%s: %s %c\n", p->element.szId, getText(textList, p->element.szId), *szAnswers);
			p = p->pLeft;
			szAnswers++;
		}
	}
	
	if(p == NULL)
		return NULL;
	else
	{
		char *szResult = p->element.szId;
		p = pStart;
		return szResult;
	}
}
