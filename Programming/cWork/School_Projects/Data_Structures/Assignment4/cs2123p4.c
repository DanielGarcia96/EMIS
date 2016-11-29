#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "cs2123p4.h"

#define VERB	10		//Assigns whether a routine is to be run verbose

/* defines for alternatives being simulated */

#define ALT_A	'A'		//Alternative A
#define ALT_B	'B'		//Alternative B
#define ALT_CURRENT	'C'	//Current Alternative

//Prototype for function that primes variables with command values
void processCommandSwitches(int argc, char *argv[], int *bVerbose, char *bAlter);

//Prototype for function that frees all memory associated with a queue
void freeQueue(Queue queue);

//Prototype for function that runs Alternative A
void runASimulation(Simulation sim, int iTimeLimit);

//Prototype for function that runs Alternative C and B
void runCSimulation(Simulation sim, int iTimeLimit);

//Prototype for function that reads from a file and adds the first arrival to the eventList
void generateArrival(Simulation sim, int iTime);

//Prototype for function that handles all actions for an arrival
void arrival(Simulation sim, Widget *widget);

//Prototype for function that handles all actions for moving the queue up
void queueUp(Simulation sim, Queue queue, Widget *pWidget);

//Prototype for function that adds an arrival to the eventList
void makeArrival(Simulation sim, Widget *pWidget);

//Prototype for function that carries out all actions associated with 'seizing'
void seize(Simulation sim, Queue queue1, Queue queue2, Server server1, Server server2);

//Prototype for function that carries out all actions associated with 'releasing'
void release(Simulation sim, Server server, Widget *widget);

//Prototype for function that displays information for leaving a System
void leaveSystem(Simulation sim, Widget widget);

//Prototype for function that processes the rest of the QElement in the queue
void restOfQ(Simulation sim, Queue queue1, Queue queue2);

//Prototype for function that displays the final statistics for the run
void displayStatistics(Simulation sim, Queue queue1, Queue queue2);

int main(int argc, char *argv[])
{
	Simulation simulation = (Simulation) malloc(sizeof(SimulationImp));
	simulation->eventList = newLinkedList();

	int bIsVerbose = 0;
	char cAlt = ALT_CURRENT;

	processCommandSwitches(argc, argv, &bIsVerbose, &cAlt);

	simulation->bVerbose = bIsVerbose;
	simulation->cRunType = cAlt;

	runSimulation(simulation, MAX_ARRIVAL_TIME);

	free(simulation);

	return 0;
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

/******************** ErrExit **************************************
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

/******************** processCommandSwitches *****************************
void processCommandSwitches(int argc, char *argv[], char **ppszCustomerFileName)
        , char **ppszQueryFileName)
Purpose:
    Checks the syntax of command line arguments and returns the filenames.  
    If any switches are unknown, it exits with an error.
Parameters:
    I   int argc                        count of command line arguments
    I   char *argv[]                    array of command line arguments
    O   char **ppszCustomerFileName     Customer File Name to return
    O   char **ppszQueryFileName        Query File Name to return 
Notes:
    If a -? switch is passed, the usage is printed and the program exits
    with USAGE_ONLY.
    If a syntax error is encountered (e.g., unknown switch), the program
    prints a message to stderr and exits with ERR_COMMAND_LINE_SYNTAX.
**************************************************************************/
void processCommandSwitches(int argc, char *argv[], int *bVerbose, char *bAlter)
{
    int i;
    if(argc < 2)
	ErrExit(ERR_BAD_INPUT, "No arguments provided");
    for (i = 1; i < argc; i++)
    {
        // check for a switch
        if(argv[i][0] == '-')
	{
		if(argv[i][1] == 'v')
			*bVerbose = VERB;
		else if(strlen(argv[i]) ==  3)
		{
			if(strcmp(argv[i], "-aA") == 0)
				*bAlter =  ALT_A;
			else if(strcmp(argv[i], "-aB") == 0)
				*bAlter =  ALT_B;
			else if(strcmp(argv[i], "-aC") == 0)
				*bAlter = ALT_CURRENT;
			else
				ErrExit(ERR_COMMAND_LINE, "Switch not found");
		}
		else
			ErrExit(ERR_COMMAND_LINE, "Switch not found");
	}
    }
}

/******************** exitUsage *****************************
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
    fprintf(stderr, "p4 -v -aABC\n");
    if (iArg == USAGE_ONLY)
        exit(USAGE_ONLY); 
    else 
        exit(ERR_COMMAND_LINE);
}

/***************************allocQNode*********************************
NodeQ *allocQNode(Queue queue, QElement element)
Purpose: Creates, allocates memory for, and returns a new NodeQ pointer
Parameters:
	O	Queue queue		Not really sure why this is here but
					why not
	I	QElement element	New element that is going to fill the
					new NodeQ
Returns:
	- newly created NodeQ pointer, function sucessful
	- NULL, error in allocating memory
Notes:
	Can be passed and empty element
***************************************(*****************************/
NodeQ *allocQNode(Queue queue, QElement element)
{
	NodeQ *pNew;
	pNew = (NodeQ *)malloc(sizeof(NodeQ));
	if(pNew == NULL)
		ErrExit(ERR_ALGORITHM, "No available memory for linked list");
	pNew->element = element;
	pNew->pNext = NULL;
	return pNew;
}

/********************************insertQ*********************************
void insertQ(Queue queue, QElement element)
Purpose: Creates a new NodeQ pointer and places it in the
	 in at the end of the queue
Parameters:
	O	Queue queue		Queue that is going to the new
					NodeQ inserted into it
	I	QElement element	QElement that is to be inserted
					into the queue
Notes:
	Can have a empty QElement inserted
*********************************************************/
void insertQ(Queue queue, QElement element)
{
	NodeQ *pNew;
	pNew = allocQNode(queue, element);
	//check for empty
	if (queue->pFoot == NULL)
	{
		queue->pFoot = pNew;
		queue->pHead = pNew;
	}
	else
	{
		//insert after foot
		queue->pFoot->pNext = pNew;
		queue->pFoot = pNew;
	}
}

/***********************newQueue*****************************
Queue newQueue(char *szQueueNm)
Purpose: Allocates new Queue and marks it as empty
Parameters:
	I	char *szQueueNm		Name of the new Queue
Returns:
	-Newly allocated Queue with its assigned name
Notes:
	-Must have some string and not be empty for the name
***********************************************************/
Queue newQueue(char *szQueueNm)
{
	Queue queue = (Queue) malloc(sizeof(QueueImp));
	queue->pHead = NULL;
	queue->pFoot = NULL;
	strcpy(queue->szQName, szQueueNm);
	queue->lQueueWaitSum = 0;
	queue->lQueueWidgetTotalCount = 0;
	return queue;
}

/*************************freeQueue*************************
void freeQueue(Queue queue)
Purpose: Frees all memory associated with a Queue and then
	 the Queue itself
Parameters:
	I	Queue queue	Queue that is to be freed
Notes:
	Queue must have at least one NodeQ
***********************************************************/
void freeQueue(Queue queue)
{
	NodeQ *node = queue->pHead;
	while(node != NULL && node->pNext != NULL)
	{
		NodeQ *temp = node;
		node = node->pNext;
		free(temp);
	}
	free(node);
	free(queue);
}

/************************removeQ**************************
int removeQ(Queue queue, QElement *pFromQElement)
Purpose: Returns and frees a NodeQ from the queue
Parameters:
	I	Queue queue		Queue that is being removed
					from
	O	QElement *pFromQElement	Element being returned from
					the move
Returns:
	TRUE - Function successfully found returned and freed Element
	NULL - Queue was empty
*********************************************************/
int removeQ(Queue queue, QElement *pFromQElement)
{
	NodeQ *p;
	// check for empty
	if (queue->pHead == NULL)
		return FALSE;
	p = queue->pHead;
	*pFromQElement = p->element;
	queue->pHead = p->pNext;
	//Removing the node could make the list empty
	//See if we need to update pFoot, due to empty list
	if (queue->pHead == NULL)
		queue->pFoot = NULL;
	free(p);
	return TRUE;
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
	free(p);
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
	while(list->pHead != NULL && list->pHead->pNext != NULL)
	{
		pTemp = pNode;	//assign temp to the node that must be freed
		list->pHead = list->pHead->pNext;	//advance the list itself to the next pointer
		pNode = list->pHead;	//assign the node to the head
		freeNode(list,pTemp);	//free the temp node
	}
	freeNode(list,pNode);	//free the final node
	free(list);	//free memory allocated for the list
}

/**************************************************
void runSimulation(Simulation sim, int iTimeLimit)
Purpose: Decides which type of Simulation needs to run
Parameters:
	I/O	Simulation sim	Simulation that is being manipulated
	I	int iTimeLimit	time limit that is used to keep simulation
				from looping infinitely
Notes:
**************************************************/
void runSimulation(Simulation sim, int iTimeLimit)
{
	switch(sim->cRunType)
	{
		case 'A':
			runASimulation(sim, iTimeLimit);
		break;
		case 'B':
			runCSimulation(sim, iTimeLimit);
		break;
		case 'C':
			runCSimulation(sim, iTimeLimit);
		break;
		default:
			ErrExit(ERR_COMMAND_LINE, "Specified Alternative not found");
	}
}

/************************runASimulation**************************
void runASimulation(Simulation sim, int iTimeLimit)
Purpose: Runs the Alternative A Simulation
Parameters:
	I/O	Simulation sim	Simulation that is being manipulated
	I	int iTimeLimit	time limit that is used to keep simulation
				from looping infinitely
Notes:
****************************************************************/

void runASimulation(Simulation sim, int iTimeLimit)
{
	Queue queue1 = newQueue("Queue 1");
	Queue queue2 = newQueue("Queue 2");

	Server server1 = (Server) malloc(sizeof(ServerImp));
	strcpy(server1->szServerName, "Server 1");
	Server server2 = (Server) malloc(sizeof(ServerImp));
	strcpy(server2->szServerName, "Server 2");

	Event event;

	generateArrival(sim, 0);	//create the first event which is an arrival
	sim->iClock = 0;		//and insert it into the sim's eventList

	if(sim->bVerbose == VERB)
		printf("Time Widget Event\n");

	while(removeLL(sim->eventList, &event) && sim->iClock < iTimeLimit)	//that way you can pop it off to create the first event
	{									//that you'll be gathering data on
		sim->iClock = event.iTime;
		switch(event.iEventType)
		{
			case EVT_ARRIVAL:
				arrival(sim, &event.widget);		//display the arrival if verbose
				queueUp(sim, queue1, &event.widget);	//add the widget to the queue, add an ARRIVAL event
				seize(sim, queue1, queue2, server1, server2);	//if server1 isn't busy add to the Queue wait time
				break;					//add a SERVER_COMPLETE event, and display, otherwise do nothing 
			case EVT_SERVER1_COMPLETE:
				release(sim, server1, &event.widget);	//release the server, display if verbose, add to total system time
				queueUp(sim, queue2, &event.widget);
				seize(sim, queue1, queue2, server1, server2);
				break;
			case EVT_SERVER2_COMPLETE:
				release(sim, server2, &event.widget);
				leaveSystem(sim, event.widget);			//display
				break;
			default:
				ErrExit(ERR_ALGORITHM, "Unknown event type: %d", event.iEventType);
		}
	}

	restOfQ(sim, queue1, queue2);			//Finish what you still have in the Queue
	displayStatistics(sim, queue1, queue2);		//Display final statistics
	freeQueue(queue1);
	freeQueue(queue2);
	freeLL(sim->eventList);
	free(server1);
	free(server2);
}

/************************runBSimulation**************************
void runBSimulation(Simulation sim, int iTimeLimit)
Purpose: Runs the Alternative B Simulation and Alternative C Simulation
Parameters:
	I/O	Simulation sim	Simulation that is being manipulated
	I	int iTimeLimit	time limit that is used to keep simulation
				from looping infinitely
Notes:
****************************************************************/
void runCSimulation(Simulation sim, int iTimeLimit)
{
	Queue queue1 = newQueue("Queue 1");
	Server server1 = (Server) malloc(sizeof(ServerImp));
	strcpy(server1->szServerName, "Server 1");
	Event event;

	generateArrival(sim, 0);	//create the first event which is an arrival
	sim->iClock = 0;		//and insert it into the sim's eventList

	if(sim->bVerbose == VERB)
		printf("Time Widget Event\n");

	while(removeLL(sim->eventList, &event) && sim->iClock < iTimeLimit)	//that way you can pop it off to create the first event
	{									//that you'll be gathering data on
		sim->iClock = event.iTime;
		switch(event.iEventType)
		{
			case EVT_ARRIVAL:
				arrival(sim, &event.widget);		//display the arrival if verbose
				queueUp(sim, queue1, &event.widget);	//add the widget to the queue, add an ARRIVAL event
				seize(sim, queue1, NULL, server1, NULL);	//if server1 isn't busy add to the Queue wait time
				break;					//add a SERVER_COMPLETE event, and display, otherwise do nothing 
			case EVT_SERVER1_COMPLETE:
				release(sim, server1, &event.widget);	//release the server, display if verbose, add to total system time
				leaveSystem(sim, event.widget);			//display
				break;
			default:
				ErrExit(ERR_ALGORITHM, "Unknown event type: %d", event.iEventType);
		}
	}

	restOfQ(sim, queue1, NULL);			//Finish what you still have in the Queue
	displayStatistics(sim, queue1, NULL);		//Display final statistics
	freeQueue(queue1);
	freeLL(sim->eventList);
	free(server1);
}

/************************generateArrival**************************
void generateArrival(Simulation sim, int iTime)
Purpose: Reads from an input file and inserts an arrival event based
	 on this information
Parameters:
	I/O	Simulation sim	Simulation from which it's eventList
				can be manipulated
	O	int iTime	Time that the event will occur 
Notes:
*****************************************************************/
void generateArrival(Simulation sim, int iTime)
{
	FILE *fpInput;
	char szInputBuffer[MAX_LINE_SIZE];
	char szToken[MAX_TOKEN];
	Event event;

	switch(sim->cRunType)
	{
		case 'A':
			fpInput = fopen("p4ACinput.txt", "r");
			break;
		case 'B':
			fpInput = fopen("p4Binput.txt", "r");
			break;
		case 'C':
			fpInput = fopen("p4ACinput.txt", "r");
			break;
		default:
			ErrExit(ERR_BAD_INPUT, "Alternative specified not found");
	}
	
	fgets(szInputBuffer, MAX_LINE_SIZE, fpInput);

	char * szPointerBuffer = szInputBuffer;

	szPointerBuffer = getToken(szPointerBuffer, szToken, MAX_TOKEN);

	event.iEventType = EVT_ARRIVAL;
	event.iTime = iTime;
	event.widget.lWidgetNr = atoi(szToken);
	
	szPointerBuffer = getToken(szPointerBuffer, szToken, MAX_TOKEN);

	event.widget.iStep1tu = atoi(szToken);

	szPointerBuffer = getToken(szPointerBuffer, szToken, MAX_TOKEN);

	event.widget.iStep2tu = atoi(szToken);
	
	insertOrderedLL(sim->eventList, event);
	fclose(fpInput);
}

/***************************arrival**********************************
void arrival(Simulation sim, Widget *pWidget)
Purpose: Sets the widget's arrival time and displays it's arrival
Parameters:
	I/O	Simulation sim	Simulation from which to access the 
				Simulation's clock
	O	Widget *pWidget	Widget that must have it's arrival
				time manipulated
********************************************************************/
void arrival(Simulation sim, Widget *pWidget)
{
	pWidget->iArrivalTime = sim->iClock;
	if(sim->bVerbose == VERB)
		printf("%4d%6ld  Arrived\n", sim->iClock, pWidget->lWidgetNr);
}

/************************queueUp**************************
void queueUp(Simulation sim, Queue queue, Widget *pWidget)
Purpose: Creates a new QElement, assigns it a Widget, insert
	 it into whichever queue was specified, and get the
	 next event if it is on the first server 
Parameters:
	I	Simulation sim 	This is used to determine 
				whether this event is supposed
				to be displayed
	I/O	Queue queue	Queue that is to be inserted into
				and determine if an arrival must
				be retrieved
	I	Widget *pWidget	Widget pointer to assign to QElement
Notes:
	
*********************************************************/
void queueUp(Simulation sim, Queue queue, Widget *pWidget)
{
	QElement newQ;
	newQ.widget = *pWidget;
	newQ.iEnterQTime = sim->iClock;

	insertQ(queue, newQ);

	queue->lQueueWidgetTotalCount++;
	
	if(sim->bVerbose == VERB)
		printf("%4d%6ld  Enter %2s\n", sim->iClock, pWidget->lWidgetNr, queue->szQName);
	if(strcmp(queue->szQName, "Queue 2") != 0)
		makeArrival(sim, pWidget);
}

/************************makeArrival**************************
void makeArrival(Simulation sim, Widget *pWidget)
Purpose: Creates an arrival and inserts into the Simulation's
	 eventList
Parameters:
	I/O	Simulation sim	Must be have an arrival inserted
				into the event list and reference
				System Time
	I	Widget *pWidget	Widget that is being passed into the
				Arrival event 
Notes:

*************************************************************/
void makeArrival(Simulation sim, Widget *pWidget)
{
	FILE *fpInput;
	char szInputBuffer[MAX_LINE_SIZE];
	char szToken[MAX_TOKEN];
	Event event;

	switch(sim->cRunType)
	{
		case 'A':
			fpInput = fopen("p4ACinput.txt", "r");
			break;
		case 'B':
			fpInput = fopen("p4Binput.txt", "r");
			break;
		case 'C':
			fpInput = fopen("p4ACinput.txt", "r");
			break;
		default:
			ErrExit(ERR_BAD_INPUT, "Alternative specified not found");
	}
	
	int i;
	for(i=0; i<pWidget->lWidgetNr; i++)
	{
		fgets(szInputBuffer, MAX_LINE_SIZE, fpInput);
	}

	char *szPointerBuffer = szInputBuffer;

	szPointerBuffer = getToken(szPointerBuffer, szToken, MAX_TOKEN);
	szPointerBuffer = getToken(szPointerBuffer, szToken, MAX_TOKEN);
	szPointerBuffer = getToken(szPointerBuffer, szToken, MAX_TOKEN);
	szPointerBuffer = getToken(szPointerBuffer, szToken, MAX_TOKEN);

	event.iEventType = EVT_ARRIVAL;
	event.iTime = atoi(szToken) + sim->iClock;
	event.widget.iArrivalTime = event.iTime;
	
	fgets(szInputBuffer, MAX_LINE_SIZE, fpInput);
	szPointerBuffer = szInputBuffer;

	szPointerBuffer = getToken(szPointerBuffer, szToken, MAX_TOKEN);
	
	event.widget.lWidgetNr = atoi(szToken);

	szPointerBuffer = getToken(szPointerBuffer, szToken, MAX_TOKEN);

	event.widget.iStep1tu = atoi(szToken);

	szPointerBuffer = getToken(szPointerBuffer, szToken, MAX_TOKEN);
	
	event.widget.iStep2tu = atoi(szToken);

	insertOrderedLL(sim->eventList, event);
	fclose(fpInput);
}

/**********************************seize***********************************
void seize(Simulation sim, Queue queue1, Queue queue2, Server server1, Server server2)
Purpose: Changes queue statistics, creates Server complete events, and displays all this
Paramters:
	I/O	Simulation sim	Must have a server completion event inserted into the 
				eventList and reference the System Time
	I/O	Queue queue1	Queue that is to be popped and have it's statistics displayed
	I/O	Queue queue2	Queue that is to be popped and have it's statistics displayed
	I/O	Server server1	Server that is to be manipulated
	I/O	Server server2	Server that is to be manipulated
Notes:
	queue2 can be NULL
	server2 can be NULL
*******************************************************/
void seize(Simulation sim, Queue queue1, Queue queue2, Server server1, Server server2)		//if server1 isn't busy add to the Queue wait time
{								//add a SERVER_COMPLETE event, and display, otherwise do nothing
	if(!(server1->bBusy) && server2 == NULL)
	{
		QElement holdQ1;
		removeQ(queue1, &holdQ1);

		if(sim->bVerbose == VERB)
			printf("%4d%6ld  Leave %2s, waited %d\n", sim->iClock, holdQ1.widget.lWidgetNr, queue1->szQName, sim->iClock - holdQ1.iEnterQTime);

		queue1->lQueueWaitSum += sim->iClock - holdQ1.iEnterQTime;
		
		Event event;
		event.iEventType = EVT_SERVER1_COMPLETE;
		event.iTime = holdQ1.widget.iStep1tu + holdQ1.widget.iStep2tu + sim->iClock;
		event.widget = holdQ1.widget;

		server1->bBusy = TRUE;
		server1->widget = holdQ1.widget;
		
		if(sim->bVerbose == VERB)
			printf("%4d%6ld  Seized %9s\n", sim->iClock, holdQ1.widget.lWidgetNr, server1->szServerName);
		
		insertOrderedLL(sim->eventList, event);
	}
	else if(server1->bBusy && server2 == NULL)
	{
		
	}
	else if(!(server1->bBusy) && !(server2->bBusy))
	{
		QElement holdQ1, holdQ2;
		removeQ(queue1, &holdQ1);
		int iCheckNull2 = removeQ(queue2, &holdQ2);

		if(iCheckNull2 != FALSE)
		{ 

			if(sim->bVerbose == VERB)
			{
				printf("%4d%6ld  Leave %2s, waited %d\n", sim->iClock, holdQ1.widget.lWidgetNr, queue1->szQName, sim->iClock - holdQ1.iEnterQTime);
				printf("%4d%6ld  Leave %2s, waited %d\n", sim->iClock, holdQ2.widget.lWidgetNr, queue2->szQName, sim->iClock - holdQ2.iEnterQTime);
			}
		
			queue1->lQueueWaitSum += sim->iClock - holdQ1.iEnterQTime;
			queue2->lQueueWaitSum += sim->iClock - holdQ2.iEnterQTime;

			Event event_com1, event_com2;

			event_com1.iEventType = EVT_SERVER1_COMPLETE;
			event_com1.iTime = holdQ1.widget.iStep1tu + sim->iClock;
			event_com1.widget = holdQ1.widget;

			server1->bBusy = TRUE;
			server1->widget = holdQ1.widget;
		
			if(sim->bVerbose == VERB)
				printf("%4d%6ld  Seized %9s\n", sim->iClock, holdQ1.widget.lWidgetNr, server1->szServerName);

			event_com2.iEventType = EVT_SERVER2_COMPLETE;
			event_com2.iTime =  holdQ2.widget.iStep2tu + sim->iClock;
			event_com2.widget = holdQ2.widget;

			server2->bBusy = TRUE;
			server2->widget = holdQ2.widget;

			if(sim->bVerbose == VERB)
				printf("%4d%6ld  Seized %9s\n", sim->iClock, holdQ2.widget.lWidgetNr, server2->szServerName);

			insertOrderedLL(sim->eventList, event_com1);
			insertOrderedLL(sim->eventList, event_com2);
		}
		else
		{
			if(sim->bVerbose == VERB)
				printf("%4d%6ld  Leave %2s, waited %d\n", sim->iClock, holdQ1.widget.lWidgetNr, queue1->szQName, sim->iClock - holdQ1.iEnterQTime);
		
			queue1->lQueueWaitSum += sim->iClock - holdQ1.iEnterQTime;

			Event event_com1;

			event_com1.iEventType = EVT_SERVER1_COMPLETE;
			event_com1.iTime = holdQ1.widget.iStep1tu + sim->iClock;
			event_com1.widget = holdQ1.widget;

			server1->bBusy = TRUE;
			server1->widget = holdQ1.widget;
		
			if(sim->bVerbose == VERB)
				printf("%4d%6ld  Seized %9s\n", sim->iClock, holdQ1.widget.lWidgetNr, server1->szServerName);

			insertOrderedLL(sim->eventList, event_com1);
		}
	}
	else if(!(server1->bBusy))
	{
		QElement holdQ1;
		removeQ(queue1, &holdQ1);
	
		if(sim->bVerbose == VERB)
			printf("%4d%6ld  Leave %2s, waited %d\n", sim->iClock, holdQ1.widget.lWidgetNr, queue1->szQName, sim->iClock - holdQ1.iEnterQTime);
		
		queue1->lQueueWaitSum += sim->iClock - holdQ1.iEnterQTime;

		Event event_com1;

		event_com1.iEventType = EVT_SERVER2_COMPLETE;
		event_com1.iTime = holdQ1.widget.iStep1tu + sim->iClock;
		event_com1.widget = holdQ1.widget;

		server1->bBusy = TRUE;
		server1->widget = holdQ1.widget;

		if(sim->bVerbose == VERB)
			printf("%4d%6ld  Seized %9s\n", sim->iClock, holdQ1.widget.lWidgetNr, server1->szServerName);

		insertOrderedLL(sim->eventList, event_com1);

		
	}
	else if(!(server2->bBusy))
	{
		QElement holdQ2;
		int iCheckNull2 = removeQ(queue2, &holdQ2);

		if(iCheckNull2 != FALSE)
		{	

			if(sim->bVerbose == VERB)
				printf("%4d%6ld  Leave %2s, waited %d\n", sim->iClock, holdQ2.widget.lWidgetNr, queue2->szQName, sim->iClock - holdQ2.iEnterQTime);
		
			queue2->lQueueWaitSum += sim->iClock - holdQ2.iEnterQTime;

			Event event_com2;

			event_com2.iEventType = EVT_SERVER2_COMPLETE;
			event_com2.iTime = holdQ2.widget.iStep2tu + sim->iClock;
			event_com2.widget = holdQ2.widget;

			server2->bBusy = TRUE;
			server2->widget = holdQ2.widget;

			if(sim->bVerbose == VERB)
				printf("%4d%6ld  Seized %9s\n", sim->iClock, holdQ2.widget.lWidgetNr, server2->szServerName);

			insertOrderedLL(sim->eventList, event_com2);
		}
		else
		{
			
		}
	}
} 

/************************release**************************
void release(Simulation sim, Queue queue, Server server, Widget *widget)
Purpose: 
Parameters:
	I	Simulation sim	 Sim through which system time is referenced
	I/O	Server server	 Server that is to be released
	I	Widget *pWidget	 Widget pointer that the widget number must
				 be referenced
Notes:
	
**************************************************/
void release(Simulation sim, Server server, Widget *pWidget)
{
	server->bBusy = FALSE;
	
	if(sim->bVerbose == VERB)
		printf("%4d%6ld  Released %s\n", sim->iClock, pWidget->lWidgetNr, server->szServerName); 
}

/************************leaveSystem**************************
void leaveSystem(Simulation sim, Widget widget)
Purpose: Adds to the SystemTimeSum and the WidgetCount
	 and displays the exit
Parameters:
	I/O	Simulation sim	Simulation that is to manipulated
	I	Widget widget	Information that must be displayed
Notes:
	
*************************************************************/
void leaveSystem(Simulation sim, Widget widget)
{
	if(sim->bVerbose == VERB)
		printf("%4d%6ld  Exit System, in system %d\n", sim->iClock, widget.lWidgetNr, sim->iClock - widget.iArrivalTime);

	sim->lSystemTimeSum += sim->iClock - widget.iArrivalTime;
	sim->lWidgetCount++;
}

/************************restOfQ**************************
void restOfQ(Simulation sim, Queue queue1, Queue queue2)
Purpose: Processes all QElements left after the time limit has been reached
Parameters:
	I/O	Simulation sim	sim that must be manipulated
	I/O	Queue queue1	queue that must be manipulated
	I/O	Queue queue2	queue that must be manipulated
Notes:
	queue2 can be NULL
*********************************************************/
void restOfQ(Simulation sim, Queue queue1, Queue queue2)
{
	QElement holdQ1, holdQ2;
	int iHoldTime1 = sim->iClock, iHoldTime2 = sim->iClock;
	if(sim->cRunType == 'C' || sim->cRunType == 'B')
	{
		while(queue1->pHead != NULL)
		{
			removeQ(queue1, &holdQ1);
			sim->lWidgetCount++;
			queue1->lQueueWaitSum += holdQ1.widget.iStep1tu + holdQ1.widget.iStep2tu + (sim->iClock - holdQ1.iEnterQTime);

			if(sim->bVerbose == VERB)
			{
				printf("%4d%6ld  Leave %2s, waited %d\n", sim->iClock, holdQ1.widget.lWidgetNr, queue1->szQName, sim->iClock - holdQ1.iEnterQTime); 
				printf("%4d%6ld  Seized Server 1\n", sim->iClock, holdQ1.widget.lWidgetNr);

				sim->iClock += holdQ1.widget.iStep1tu + holdQ1.widget.iStep2tu;

				printf("%4d%6ld  Released Server1\n", sim->iClock, holdQ1.widget.lWidgetNr); 
				printf("%4d%6ld  Exit System, in system %d\n", sim->iClock, holdQ1.widget.lWidgetNr, sim->iClock - holdQ1.widget.iArrivalTime);
				sim->lSystemTimeSum += sim->iClock - holdQ1.widget.iArrivalTime;
			}
			else
			{
				sim->iClock += holdQ1.widget.iStep1tu + holdQ1.widget.iStep2tu;
				sim->lSystemTimeSum += sim->iClock - holdQ1.widget.iArrivalTime;
			}
		}
	}
	if(sim->cRunType == 'A')
	{
		int bCheckRemove = TRUE;
		while(bCheckRemove != FALSE)
		{
			//pop off first queue
			bCheckRemove = removeQ(queue1, &holdQ1);
				//display leaving and seizing using iHoldTime1
			if(sim->bVerbose == VERB)
			{
				printf("%4d%6ld  Leave %2s, waited %d\n", iHoldTime1, holdQ1.widget.lWidgetNr, queue1->szQName, iHoldTime1 - holdQ1.iEnterQTime); 
				printf("%4d%6ld  Seized Server 1\n", iHoldTime1, holdQ1.widget.lWidgetNr);
			}
				//add to system time and queue time
			sim->lSystemTimeSum += (iHoldTime1 - holdQ1.widget.iArrivalTime) + holdQ1.widget.iStep1tu;
			queue1->lQueueWaitSum += iHoldTime1 - holdQ1.widget.iArrivalTime;
			iHoldTime1 += holdQ1.widget.iStep1tu;
				//advance the iHoldTime1 the amount of time widget is in the server
			//throw this element into the second queue
			insertQ(queue2, holdQ1);
			//pop off second queue
			queue2->lQueueWidgetTotalCount++;
			removeQ(queue2, &holdQ2);
				//display holdQ1 entering queue2 using iHoldTime1
			if(sim->bVerbose == VERB)
			{
				printf("%4d%6ld  Enter %2s\n", iHoldTime1, holdQ1.widget.lWidgetNr, queue2->szQName);
				printf("%4d%6ld  Leave %2s, waited %d\n", iHoldTime2, holdQ2.widget.lWidgetNr, queue2->szQName, iHoldTime2 - holdQ2.iEnterQTime); 
				printf("%4d%6ld  Seized Server 2\n", iHoldTime2, holdQ2.widget.lWidgetNr);
			}
				//display leaving and seizing using iHoldTime2
				//add to system time and queue time
			sim->lSystemTimeSum += (iHoldTime2 - holdQ2.widget.iArrivalTime) + holdQ2.widget.iStep1tu;
			sim->lWidgetCount++;
			queue2->lQueueWaitSum += iHoldTime2 - holdQ2.widget.iArrivalTime;
			iHoldTime2 += holdQ2.widget.iStep2tu;
				//exit system using iHoldTime2 - iArrivalTime
			if(sim->bVerbose == VERB)
				printf("%4d%6ld  Exit System, in system %d\n", iHoldTime2, holdQ2.widget.lWidgetNr, iHoldTime2 - holdQ2.widget.iArrivalTime);
			
		}
		while(queue2->pHead != NULL)
		{
			removeQ(queue2, &holdQ2);
				//display holdQ1 entering queue2 using iHoldTime1
			if(sim->bVerbose == VERB)
			{
				printf("%4d%6ld  Leave %2s, waited %d\n", iHoldTime2, holdQ2.widget.lWidgetNr, queue2->szQName, iHoldTime2 - holdQ2.iEnterQTime); 
				printf("%4d%6ld  Seized Server 2\n", iHoldTime2, holdQ2.widget.lWidgetNr);
			}
				//display leaving and seizing using iHoldTime2
				//add to system time and queue time
			sim->lSystemTimeSum += (iHoldTime2 - holdQ2.widget.iArrivalTime) + holdQ2.widget.iStep1tu;
			sim->lWidgetCount++;
			queue2->lQueueWaitSum += iHoldTime2 - holdQ2.widget.iArrivalTime;
			iHoldTime2 += holdQ2.widget.iStep2tu;
				//exit system using iHoldTime2 - iArrivalTime
			if(sim->bVerbose == VERB)
				printf("%4d%6ld  Exit System, in system %d\n", iHoldTime2, holdQ2.widget.lWidgetNr, iHoldTime2 - holdQ2.widget.iArrivalTime);
			//pop off second queue
				//display leaving and seizing using iHoldTime2
				//add to system time and queue time
				//exit system using (iHoldTime2 + iStep2tu) - iArrivalTime
				//advance the iHoldTime2 the amount of time widget is in the server
		}
		
	}
}

/************************displayStatistics**************************
void displayStatistics(Simulation sim, Queue queue1, Queue queue2)
Purpose: Displays the statistics at the end of the simulation
Parameters:
	I	Simulation sim		Sim information must be obtained here
	I	Queue queue1		queue1 information must be obtained here
	I	Queue queue2		queue2 information must be obtained here
Notes:
	queue2 must be NULL
*******************************************************************/
void displayStatistics(Simulation sim, Queue queue1, Queue queue2)
{
	printf("Widgets Processed: %ld\n", sim->lWidgetCount);
	printf("Average Time in System: %ld\n", sim->lSystemTimeSum/sim->lWidgetCount);
	printf("Average Queue Time in Step 1: %ld\n", (queue1->lQueueWaitSum)/(queue1->lQueueWidgetTotalCount));
	if(queue2 != NULL)
		printf("Average Queue Time in Step 2: %ld\n", (queue2->lQueueWaitSum)/(queue2->lQueueWidgetTotalCount));
}
