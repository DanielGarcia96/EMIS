#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "cs2123p3.h"

//Prototype of function that frees all memory associated with a LinkedList
void freeLL(LinkedList list);

//Prototype of function that fills in information for three events based on char input
void fillEvents(Event *arrivalEvent, Event *departureEvent, Event *nextEvent, char * szInput, int iDecision, int iCTime);

//Prototype of function that displays the contents of a LinkedList
void printList(LinkedList list);

int main(int argc, char *argv[])
{
	Simulation sim = malloc(sizeof(SimulationImp));	//allocate the memory for a Simulation
	sim->eventList = newLinkedList();  //Create a new LinkedList within this simulation
	
	runSimulation(sim, 100);
	
	freeLL(sim->eventList);	//Free up all memory associated with the eventList
	
	free(sim); //Free up the linked list itself
	
	return 0;
}

/*************************newLinkedList****************************
LinkedList newLinkedList()
Purpose: Creating a new LinkedList via dynamic memory
Returns: Returns a newly allocated LinkedList
Notes:
	List is NULL upon creation
******************************************************************/
LinkedList newLinkedList()
{
	LinkedList list = (LinkedList) malloc(sizeof(LinkedListImp));
	//Mark the list as empty
	list->pHead = NULL;	// empty list
	return list;
}

/*************************allocateNodeLL*****************************
NodeLL *allocateNode(LinkedList list, Element value)
Purpose: Creates a new Node that will then be added to a LinkedList
Parameters:
        I       LinkedList list         LinkedList that is to be read from
        I/O     Element value           Element that is to fill the new node
Returns: Returns a newly allocated and intialized NodeLL
Notes:
        The LinkedList parameter seems utterly pointless
******************************************************************/
NodeLL *allocateNode(LinkedList list, Event value)
{
	NodeLL *pNew;
	pNew = (NodeLL *)malloc(sizeof(NodeLL));	//declare and allocate a new NodeLL
	if (pNew == NULL)
		ErrExit(ERR_ALGORITHM, "No available memory for linked list");		//There was a problem allocating the memory
	pNew->event = value;	//Assign it that event
	pNew->pNext = NULL;	//Give the next pointer a non-garbage value
	return pNew;
}

/******************************searchLL******************************
NodeLL *searchLL(LinkedList list, Key match, NodeLL **ppPrecedes
Purpose: Searches a LinkedList for where a node should go based on Event Time
Parameters:
        I       LinkedList LL           LinkedList that is read from
        I       Key match               Pattern that is searched for
        I/O     **ppPrecedes            Pointer to a pointer of what
					precedes the node looked for
Returns: The Node that was matched to the pattern
Notes:
        Needs a non-NULL LinkedList
	Assumes that the list it is reading is ordered already
 ********************************************************************/
NodeLL *searchLL(LinkedList list, int match, NodeLL **ppPrecedes)
{
	NodeLL *p;
	//used when the list is empty or we need to insert at the beginning
	*ppPrecedes = NULL;
	// Traverse the through the list looking for where key belongs or
	// the end of the list.
	for(p = list->pHead; p != NULL; p = p->pNext)
	{
		if (match == p->event.iTime)
			return p;
		if (match < p->event.iTime)
			return NULL;
		*ppPrecedes = p;
	}
	//Not found return NULL
	return NULL;
}

/******************************insertOrderedLL******************************
NodeLL *insertOrderedLL(LinkedList list, Element value)
Purpose: Inserts a node in an orderly fashion into a LinkedList
Parameters:
        I       LinkedList list         LinkedList that is read from
        I       Event value             Event that fills a new Node
Returns: The newly created Node that is inserted into a list
Notes:
        Needs a non-NULL LinkedList
***************************************************************************/
NodeLL *insertOrderedLL(LinkedList list, Event value)
{
	NodeLL *pNew, *pFind, *pPrecedes;
	// see if it already exists
	pFind = searchLL(list, value.iTime, &pPrecedes);

	// doesn't already exist.  Allocate a node and insert.
	pNew = allocateNode(list, value);

	// Check for inserting at the beginning of the list
	// this will also handle when the list is empty
	if (pPrecedes == NULL)
	{
		//Insert at beginning
		pNew->pNext = list->pHead;
		list->pHead = pNew;
	}
	else
	{
		//Insert where it goes
		pNew->pNext = pPrecedes->pNext;
		pPrecedes->pNext = pNew;
	}
	return pNew;
}

/*****************************freeNode*******************************
void freeNode(LinkedList list, NodeLL *pNode)
Purpose: Frees up memory for a specified node
Parameters:
        I       LinkedList list         LinkedList that is read from
        I/O     NodeLL *pNode           Node pointer that is freed
Notes:
        Needs a non-NULL LinkedList
********************************************************************/
void freeNode(LinkedList list, NodeLL *pNode)
{
	free(pNode);
}

/*****************************removeLL*******************************
int removeLL(LinkedList list, Element *pValue
Purpose: Pulls a LinkedList Node from the LinkedList
Parameters:
        I/O     LinkedList list         LinkedList that is manipulated
        I/O     Element *pValue         Element pointer that is returned
Notes:
        Needs a non-NULL LinkedList
********************************************************************/
int removeLL(LinkedList list, Event *pValue)
{
	NodeLL *p;
	if (list->pHead == NULL)
		return FALSE;
	*pValue = list->pHead->event;
	p = list->pHead;
	list->pHead = list->pHead->pNext;
	//??
	return TRUE;
}

/************************freeLL**************************
void freeLL(LinkedList list)
Purpose: Frees all the memory associated with a LinkedList
	 and then frees the list
Parameters:
	I	LinkedList list		LinkedList to be freed
Notes:
	This assumes the LinkedList is done with and it cannot
	be recovered afterwards.
********************************************************/
void freeLL(LinkedList list)
{
	NodeLL *pNode = list->pHead;	//start the first NodeLL at the pHead of the list 
	NodeLL *pTemp;	//temp node that can be freed safely
	while(list->pHead->pNext != NULL)
	{
		pTemp = pNode;	//assign temp to the node that must be freed
		list->pHead = list->pHead->pNext;	//advance the list itself to the next pointer
		pNode = list->pHead;	//assign the node to the head
		freeNode(list,pTemp);	//free the temp node
	}
	freeNode(list,pNode);	//free the final node
	free(list);	//free memory allocated for the list
}

/***********************printList****************************
void printList(LinkedList list)
Purpose: Displays the values of the LinkedList in a formatted fashion
Parameters:
	O	LinkedList list		LinkedList that is to be displayed
Notes:
	Needs a non-NULL LinkedList or segment fault
************************************************************/
void printList(LinkedList list)
{
	NodeLL *pStart = list->pHead;	//Make a node that keeps track of the very first element
	char szCurrentType[12];		//String that keeps track of current eventType
	printf("%-10s%-12s%s\n", "TIME", "PERSON", "EVENT");
	while(list->pHead != NULL)
	{
		(list->pHead->event.iEventType == EVT_ARRIVE) ? strcpy(szCurrentType,"Arrive") : strcpy(szCurrentType,"Depart");
		//Ternary deciding the eventType
		printf("%-10d%-12s%s\n", list->pHead->event.iTime, list->pHead->event.person.szName, szCurrentType);
		list->pHead = list->pHead->pNext;	//Advance the list
	}
	list->pHead = pStart;	//Bring the list back to the very beginning
}

/***********************fillEvents**************************************************************************************
void fillEvents(Event *arrivalEvent, Event *departureEvent, Event *nextEvent, char * szInput, int iDecision, int iCtime)
Purpose: Fills in arrival and departure for three Event pointers based off of a string of input
Parameters:
	I/O	Event *arrivalEvent	An arrival event that already has some information but needs the rest filled in
	O	Event *departureEvent	A departure Event that needs to have it's information filled in.
	I/O	Event *nextEvent	Next arrival event that sets up the function for it's next call
	I	char *szInput		String that holds the information being transferred to the Events
	I	int iDecision		Int that decides which case the function is to carry out
	I	int iCtime		Current time of the simulation	
***********************************************************************************************************************/
void fillEvents(Event *pArrivalEvent, Event *pDepartureEvent, Event *pNextEvent, char * szInput, int iDecision, int iCtime)
{
	char szToken[MAX_TOKEN];									//Create a char array to store a token
	szInput = getToken(szInput, szToken, MAX_TOKEN);						//Get the first token
	
	switch(iDecision)										//Decide whether this is the beginning of the list
	{
		case 1:											//Beginning, so I won't have previous data filling
			pArrivalEvent->iEventType = EVT_ARRIVE;						//to rely on, which means this is where I start
			pDepartureEvent->iEventType = EVT_DEPART;
		
			strcpy(pArrivalEvent->person.szName, szToken);					//Copy name into both events
			strcpy(pDepartureEvent->person.szName, szToken);
			
			szInput = getToken(szInput, szToken, MAX_TOKEN);				//Get the next token because there is a glitch
			
			pArrivalEvent->iTime = iCtime;							//iCtime should be zero making this the very first event
			pArrivalEvent->person.iDepartUnits = atoi(szToken);				//Store how long they stick around at the airport
			
			pDepartureEvent->person.iDepartUnits = pArrivalEvent->person.iDepartUnits;	//Depart units will be the same for both events, so equate the two
			pDepartureEvent->iTime = iCtime + pArrivalEvent->person.iDepartUnits;		//Departure occurs iDepartUnits after iCtime (arrival)
			
			szInput = getToken(szInput, szToken, MAX_TOKEN);				//Get the next token
			
			pNextEvent->iEventType = EVT_ARRIVE;						//Automatically know that the next event will be an arrival
			pNextEvent->iTime = iCtime + atoi(szToken);					//Next arrival occurs x units after iCtime (last arrival)
		break;
		default:										//Middle of or last of list so this arrival's
			strcpy(pArrivalEvent->person.szName, szToken);					//iTime and iEventType have already been filled in
			
			pDepartureEvent->iEventType = EVT_DEPART;					//Mark as Departure
			strcpy(pDepartureEvent->person.szName, szToken);					//Copy name into both events
			
			szInput = getToken(szInput, szToken, MAX_TOKEN);				//Get next token
			
			pArrivalEvent->person.iDepartUnits = atoi(szToken);				//Arrival is now complete
			
			pDepartureEvent->person.iDepartUnits = pArrivalEvent->person.iDepartUnits; 	//The events departUnits are the same
			pDepartureEvent->iTime = pArrivalEvent->iTime + pArrivalEvent->person.iDepartUnits;//departure can then be inferred from arrival
			
			szInput = getToken(szInput, szToken, MAX_TOKEN);				//Get next token
			
			pNextEvent->iEventType = EVT_ARRIVE;						//Automatically know that the next event will be an arrival
			pNextEvent->iTime = iCtime + atoi(szToken);					//Next arrival occurs x units after iCtime (last arrival)
		break;
	}
}

/************************************runSimulation*****************************************
void runSimulation(Simulation simulation, int iTimeLimit)
Purpose: Function that reads from a file and allocates nodes in a linkedList
	 then displays them at the end of the simulation
Parameters:
	O	Simulation simulation	Simulation struct pointer that holds Events
	I	int iTimeLimit		A time limit for debugging that keeps the function
					from being stuck in an infinite loop
Notes:
	Simulation and eventList memory must be allocated before the function runs
******************************************************************************************/
void runSimulation(Simulation simulation, int iTimeLimit)
{
	char szInputBuffer[MAX_LINE_SIZE];	//Standard Input Buffer
	FILE *fpInput = fopen("p3Input.txt","r");	//Retrieve the input file
	simulation->iClock = 0;		//Start the clock off at 0
	Event nextEvent, arrivalEvent, departureEvent;		//Create some holding Events
	char *szCheckInput = fgets(szInputBuffer, MAX_LINE_SIZE, fpInput);	//Get the first string
	
	while(simulation->iClock < iTimeLimit && szCheckInput != NULL)
	{
		if(simulation->eventList->pHead == NULL)
		{
			fillEvents(&arrivalEvent, &departureEvent, &nextEvent, szInputBuffer, 1, simulation->iClock);
			//fill in the first three Events

			insertOrderedLL(simulation->eventList, arrivalEvent);
			insertOrderedLL(simulation->eventList, departureEvent);
			//insert the first two into the eventList

			arrivalEvent = nextEvent;	//set up the next arrival by assigning it to the
							//next event
			simulation->iClock++;		//advance the clock

			szCheckInput = fgets(szInputBuffer, MAX_LINE_SIZE, fpInput);	//get the next string
		}
		else
		{
			if(arrivalEvent.iTime != simulation->iClock)	//nothing's going to happen now so 
				simulation->iClock++;			//just mark time until the next event 
			else
			{
				fillEvents(&arrivalEvent, &departureEvent, &nextEvent, szInputBuffer, 0, simulation->iClock);
				//fill in the next three events
				
				insertOrderedLL(simulation->eventList, arrivalEvent);
				insertOrderedLL(simulation->eventList, departureEvent);
				//insert one arrival and one departure

				arrivalEvent = nextEvent; 	//set up the next arrival by assigning it to the
								//next event
				simulation->iClock++;		//advance the clock

				szCheckInput = fgets(szInputBuffer, MAX_LINE_SIZE, fpInput);	//get the next string
			}
		}
	}
	
	printList(simulation->eventList);
	//print what's in the list
	printf("%-10d%-12s%s\n", simulation->iClock, "SIMULATION", "TERMINATES");
	//signal the end of simulation
	fclose(fpInput);
	//close the file you were working with
}

/**************************************getToken*******************************
char * getToken(char *pszInputTxt, char szToken[], int iTokenSize)
Purpose:
    Examines the input text to return the next token.  It also
    returns the position in the text after that token.  This function
    does not skip over white space, but it assumes the input uses
    spaces to separate tokens.
Parameters:
    I   char *pszInputTxt       input buffer to be parsed
    O   char szToken[]          Returned token.
    I   int iTokenSize          The size of the token variable.  This is used
                                to prevent overwriting memory.  The size
                                should be the memory size minus 1 (for
                                the zero byte).
Returns:
    Functionally:
        Pointer to the next character following the delimiter after the token.
        NULL - no token found.
    szToken parm - the returned token.  If not found, it will be an
        empty string.
Notes:
    - If the token is larger than the szToken parm, we return a truncated value.
    - If a token isn't found, szToken is set to an empty string
    - This function does not skip over white space occurring prior to the token.
**************************************************************************/
char * getToken(char *pszInputTxt, char szToken[], int iTokenSize)
{
    int iDelimPos = 0;                      // found position of delim
    int iCopy;                          // number of characters to copy
    char szDelims[20] = " \n\r";        // delimiters
    szToken[0] = '\0';

    // check for NULL pointer
    if (pszInputTxt == NULL)
        ErrExit(ERR_ALGORITHM
        , "getToken passed a NULL pointer");

    // Check for no token if at zero byte
    if (*pszInputTxt == '\0')
        return NULL;

    while(*pszInputTxt == ' ')		//had to modify this so it could handle
    {					//extra spaces. It just skips them if it finds them
	pszInputTxt++;
    }

    // get the position of the first delim
    iDelimPos = strcspn(pszInputTxt, szDelims);

    // if the delim position is at the first character, return no token.
    if(iDelimPos == 0)
       return NULL;

    // see if we have more characters than target token, if so, trunc
    if (iDelimPos > iTokenSize)
        iCopy = iTokenSize;             // truncated size
    else
        iCopy = iDelimPos;

    // copy the token into the target token variable
    memcpy(szToken, pszInputTxt, iCopy);
    szToken[iCopy] = '\0';              // null terminate

    // advance the position
    pszInputTxt += iDelimPos;
    if (*pszInputTxt == '\0')
        return pszInputTxt;
    else
        return pszInputTxt + 1;
}

/*************************************************************************
 void ErrExit(int iexitRC, char szFmt[], ... )
Purpose:
    Prints an error message defined by the printf-like szFmt and the
    corresponding arguments to that function.  The number of
    arguments after szFmt varies dependent on the format codes in
    szFmt.
    It also exits the program with the specified exit return code.
Parameters:
    I   int iexitRC             Exit return code for the program
    I   char szFmt[]            This contains the message to be printed
                                and format codes (just like printf) for
                                values that we want to print.
    I   ...                     A variable-number of additional arguments
                                which correspond to what is needed
                                by the format codes in szFmt.
Notes:
    - Prints "ERROR: " followed by the formatted error message specified
      in szFmt.
    - Prints the file path and file name of the program having the error.
      This is the file that contains this routine.
    - Requires including <stdarg.h>
Returns:
    Returns a program exit return code:  the value of iexitRC.
**************************************************************************/
void ErrExit(int iexitRC, char szFmt[], ... )
{
    va_list args;               // This is the standard C variable argument list type
    va_start(args, szFmt);      // This tells the compiler where the variable arguments
                                // begins.  They begin after szFmt.
    printf("ERROR: ");
    vprintf(szFmt, args);       // vprintf receives a printf format string and  a
                                // va_list argument
    va_end(args);               // let the C environment know we are finished with the
                                // va_list argument
    printf("\n");
    exit(iexitRC);
}

/***********************************exitUsage******************************
void exitUsage(int iArg, char *pszMessage, char *pszDiagnosticInfo)
Purpose:
    In general, this routine optionally prints error messages and diagnostics.
    It also prints usage information.

    If this is an argument error (iArg >= 0), it prints a formatted message
    showing which argument was in error, the specified message, and
    supplemental diagnostic information.  It also shows the usage. It exits
    with ERR_COMMAND_LINE.

    If this is a usage error (but not specific to the argument), it prints
    the specific message and its supplemental diagnostic information.  It
    also shows the usage and exist with ERR_COMMAND_LINE.

    If this is just asking for usage (iArg will be -1), the usage is shown.
    It exits with USAGE_ONLY.
Parameters:
    I int iArg                      command argument subscript or control:
                                    > 0 - command argument subscript
                                    0 - USAGE_ONLY - show usage only
                                    -1 - USAGE_ERR - show message and usage
    I char *pszMessage              error message to print
    I char *pszDiagnosticInfo       supplemental diagnostic information
Notes:
    This routine causes the program to exit.
**************************************************************************/
void exitUsage(int iArg, char *pszMessage, char *pszDiagnosticInfo)
{
    switch (iArg)
    {
        case USAGE_ERR:
            fprintf(stderr, "Error: %s %s\n"
                , pszMessage
                , pszDiagnosticInfo);
            break;
        case USAGE_ONLY:
            break;
        default:
            fprintf(stderr, "Error: bad argument #%d.  %s %s\n"
                , iArg
                , pszMessage
                , pszDiagnosticInfo);
    }
    // print the usage information for any type of command line error
    fprintf(stderr, "p2 -c customerFileName -q queryFileName\n");
    if (iArg == USAGE_ONLY)
        exit(USAGE_ONLY);
    else
	exit(ERR_COMMAND_LINE);
}
