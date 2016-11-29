/****************************************************
cs2123p2.c by Daniel Kane Garcia
Purpose:
	Convert infix queries to postfix queries, and
	then checks an array of customers to see
	which match that query.
Command Parameters:
	Used in other file.
Input:
	Takes a char pointer and Out.
Results:
	Returns an Out.
Returns:
	0 Conversion sucessful
	801 Missing right parenthesis
	802 Missing left parenthesis
Notes:
	Must have a none NULL char pointer.
****************************************************/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
/****************************************************
cs2123p1.h
Purpose:
	Provides struct implementations and typedefs.
Notes:
	Must link with cs2123p2Driver.o/exe in order
	to use any function associated with these
	structs.
****************************************************/
#include "cs2123p2.h"

//function prototype for main processing of infix input
int convertToPostFix(char * pszInfix, Out out);

//function prototype for right parenthesis handling
int isGoodRParen(Stack * stack, Out * out);

//function prototype for operator handling
void isOperator(Stack * stack, Out * out, Element * element);

//function prototype for the end of tokens processing
int endTokens(Stack * stack, Out * out);

//function prototype that evaluates postfix queries
void evaluatePostFix(Out out , Customer cutomerM[], int iNumCustomer, QueryResult resultM[]);

//function prototype that handles ONLY operator evaluations 
int only(Customer *pCustomer, Trait *pTrait);

//function prototype that handles = operator evaluations
int atLeastOne(Customer *pCustomer, Trait *pTrait);

//funciton prototype that handles the end of query processing
int finalCheck(Stack * stack);

//function prototype that handles the display customers
void printCustomerData(Customer customerM[], int iNumCustomer);

/****************************convertToPostFix******************************/
/*Purpose:	        Converts char array expressions in infix to a     */
/*			token version of a struct pointer type Out.       */
/*Parameters:                                                             */
/*		I	char * pszInfix		char pointer of the infix */
/*						expression to be converted*/
/*		O	Out out			OutImp pointer that will  */
/*						store the finished data.  */
/*Returns:                                                                */
/*		0	Conversion successful                             */
/*		801	Missing right parenthesis                         */
/*		802	Missing left parenthesis                          */
/**************************************************************************/
int convertToPostFix(char * pszInfix, Out out)
{
	Stack stack = newStack();	//Create a stack for element manipulation
	char szMyToken[50];
	pszInfix = getToken(pszInfix, szMyToken, MAX_TOKEN);	
	while(pszInfix != NULL)
	{
		//Create an automatic Element variable
		Element element;
		//Assign the element's token to pszInfix token
		memcpy(element.szToken,szMyToken,strlen(szMyToken));
		//Null terminate token
		element.szToken[strlen(szMyToken)] = '\0';
		//Assign all characteristics that go with that element token via the categorize() function
		categorize(&element);
		if(element.iCategory == CAT_OPERAND)
			addOut(out, element); 	//If it's an operand, add it to the out
		else if(element.iCategory == CAT_LPAREN)
			push(stack, element);  //If it's a left parenthesis, push it on to the stack 
		else if(element.iCategory == CAT_RPAREN)
		{
			//Use a boolean int to find out if there is a matching parenthesis
			//Assign it to the exit value of isGoodRParen
			int bGoodMatch = isGoodRParen(&stack, &out);
			if(!bGoodMatch)
			{
				//Not a matching a parenthesis so free stack here
				freeStack(stack);
				//Return a warning so Out is not used
				return WARN_MISSING_LPAREN;
			}
		}
		else //Must be an operator
			isOperator(&stack, &out, &element);
		//Iterate through the rest of the tokens
		pszInfix = getToken(pszInfix, szMyToken, MAX_TOKEN);
	}
	//End of the tokens
	int bGoodEnd = endTokens(&stack, &out);
	if(bGoodEnd != 0) //If the conversion isn't successful
	{
		freeStack(stack);
		return WARN_MISSING_RPAREN;
	}
	//Free allocated memory
	freeStack(stack);
	//Return 0 to indicate that function executed successfully and so it is safe to use the Out.
	return 0;
}

/*************************isGoodRParen**************************/
/*int isGoodRParen(Stack * stack, Out * out);                  */
/*Purpose:                                                     */
/*	This function checks to see if there is a matching left*/
/*	parenthesis for the right parenthesis that was         */
/*	encountered. As it goes it adds to the Out.            */
/*Parameters:                                                  */
/*	I/O	Stack * stack	Stack pointer to access and    */
/*				change data in the stack.      */
/*	O	Out * out	Out pointer to add to.         */
/*Notes:                                                       */
/*	Needs a none null stack                                */
/*	Needs a none null out                                  */
/*Returns:                                                     */
/*	1	Found a matching left parenthesis.             */
/*	0	Did not find a matching left parenthesis.      */
/***************************************************************/

int isGoodRParen(Stack * stack, Out * out)
{
	int bIsGood = FALSE;
		while(!(isEmpty(*stack)))
		{
			//Check to see if the element that your looking at is a left parenthesis	
			if((*stack)->stackElementM[(*stack)->iCount-1].iCategory == CAT_LPAREN)
			{
				//If there is a matching parenthesis, then indicate it
				bIsGood = TRUE;
				//Pop the stack one more time to get rid of the left parenthesis, then stop popping
				pop(*stack);
				break;
			}
			//if it's not a left parenthesis, then add it to the out
			addOut(*out, pop(*stack));
		}
	return bIsGood;
}

/***************************isOperator******************************/
/*void isOperator(Stack * stack , Out * out, Element * element);   */
/*Purpose:                                                         */
/*	This function correctly adds operators to the out pointer  */
/*	based on the operator that was passed in.                  */
/*Parameters:                                                      */
/*	I/O	Stack * stack 		Stack pointer to modify and*/
/*					access data.               */
/*	O	Out * out		Out pointer to add to.     */
/*	I	Element * element	Element pointer to check   */
/*					against the rest of the    */
/*					stack elements.            */
/*Notes:                                                           */
/*	Needs a none null stack                                    */
/*	Needs a none null out                                      */
/*******************************************************************/

void isOperator(Stack * stack, Out * out, Element * element)
{
	while(!(isEmpty(*stack)))
	{
		//Make another Element for the top element
		Element TopElement; 
		//Assign it the top element on the stack
		TopElement = topElement(*stack);
		//If the new element's precendence is greater than the top element
		//then stop popping elements off the stack and adding them out
		//and push the new element onto the stack.
		//Can't out a parenthesis so break when that is encountered
		if(TopElement.iCategory == CAT_LPAREN)
			break;
		else if((*element).iPrecedence > TopElement.iPrecedence)
			break;
		else
			addOut(*out,pop(*stack));
	}
	push(*stack, *element);
}

/*************************endTokens***************************/
/*int endTokens(Stack * stack, Out * out);                   */
/*Purpose:                                                   */
/*	This function adds all stack elements to the Out     */
/*	pointer that was provided. It also checks for missing*/
/*	right parenthesis                                    */
/*Parameters:                                                */
/*	I/O	Stack * stack	stack pointer to modify and  */
/*				access data                  */
/*	O	Out * out	Out pointer to add to.       */
/*Notes:                                                     */
/*	Needs a none null stack                              */
/*	Needs a none null out                                */
/*Returns:                                                   */
/*	1	No unmatched left parenthesis found.         */
/*		Conversion successful.                       */
/*	0	Found an unmatched left parenthesis.         */
/*************************************************************/

int endTokens(Stack * stack, Out * out)
{
	int bFoundRight = FALSE;
	while(!isEmpty(*stack))
	{
		//If there exists a left parenthesis, then that means it was never
		//popped off by a matching right parenthesis. So return a warning.
		if((*stack)->stackElementM[(*stack)->iCount-1].iCategory == CAT_LPAREN)
		{
			//free stack here because function won't reach the end
			bFoundRight = TRUE;
			//Return a warning so that the Out is not used
			break;
		}
		//Pop and addOut until stack is empty to obtain the rest of the operators
		addOut(*out,pop(*stack));
	}
	return bFoundRight;
}

/**************************************evaluatePostFix******************************************/
/*void evaluatePostFix(Out out, Customer customerM[], int iNumCustomer, QueryResult resultM[]);*/
/*Purpose:                                                                                     */
/*	Go through the Out and evaluate which ever Customers in the array meet the             */
/*	query. Then store these results in an array of booleans that correspond to indexes in  */
/*	Customer array.                                                                        */
/*Parameters:                                                                                  */
/*	I	Out out			Out, which is the query being processed                */
/*	I	Customer customerM[]	Customer array which is being checked for the query    */
/*	I	int iNumCustomer	Number or Customers in the Customer array              */
/*	O	QueryResult resultM[]	Results of evaluating the query                        */
/*Notes:                                                                                       */
/*	All pointers must be none null                                                         */
/***********************************************************************************************/
void evaluatePostfix(Out out, Customer customerM[], int iNumCustomer, QueryResult resultM[])
{
	int i;
	//Loop through customers to check all for a certain query
	for(i = 0; i < iNumCustomer; i++)
	{
		//Make a new stack to push different operands and operation results onto
		Stack stack = newStack();
		int j;
		//Loop through all out elements, or the query
		for(j = 0; j < out->iOutCount; j++)
		{
			//Make a new element and assign it to the most recent out element
			Element newElement = out->outM[j];

			//if it's an operand then I need to do something
			//with it. So push it onto the stack.

			if(newElement.iCategory == CAT_OPERAND)
				push(stack, newElement);
			else
			{
				//Element that is eventually going to be pushed onto the stack
				Element pushThis;
				//Make element that will stand in for the first operand
				//Pop the stack and assign it that 
				Element elementOperand1 = pop(stack);
				//Make element that will stand in for the second operand
				//Pop the stack and assign it that 
				Element elementOperand2 = pop(stack);
				//Make a char array to hold the result of an int to string conversion.
				char szConvertInt[2];

				if(strcmp(newElement.szToken, "AND")==0 || strcmp(newElement.szToken, "OR")==0) //If it's an AND or OR then special things need to be done
				{
					//Create int versions of the operand tokens
					int firstElement = atoi(elementOperand1.szToken);
					int secondElement = atoi(elementOperand2.szToken);

					if(strcmp(newElement.szToken, "AND")==0) //If it's an AND then logical 'and' the int versions
					{
						//Move the result of the logical operation into the convertString
						sprintf(szConvertInt, "%d", (firstElement && secondElement));
						//Copy the convert String into pushThis's boolean token
						strcpy(pushThis.szBoolean, szConvertInt);
						//Push pushThis onto the stack
						push(stack, pushThis);
					}
					else //Else logical 'or' the int versions
					{
						sprintf(szConvertInt, "%d", (firstElement || secondElement));
					
						strcpy(pushThis.szBoolean, szConvertInt);
						push(stack, pushThis);
					} 
				}
				else
				{
					//Need a trait to different trait tokens from the operands into
					Trait newTrait;

					strcpy(newTrait.szTraitValue, elementOperand1.szToken);
					strcpy(newTrait.szTraitType, elementOperand2.szToken);

					//Execute specialized functions based on the operator
					if(strcmp(newElement.szToken, "=")==0)
					{
						sprintf(szConvertInt, "%d", atLeastOne(&customerM[i], &newTrait));
						strcpy(pushThis.szBoolean, szConvertInt);
						push(stack, pushThis);
					}
					else if(strcmp(newElement.szToken, "NOTANY")==0)
					{
						sprintf(szConvertInt, "%d", notAny(&customerM[i], &newTrait));
						strcpy(pushThis.szBoolean, szConvertInt);
						push(stack, pushThis);
					}
					else
					{
						sprintf(szConvertInt, "%d", only(&customerM[i], &newTrait));
						strcpy(pushThis.szBoolean, szConvertInt);
						push(stack, pushThis);
					}
				}
			}
		}
		resultM[i] = finalCheck(&stack); //At the end of the all the changing there will
						 //there will be only one value left and it will
		freeStack(stack);		 //be a boolean. If true, store it in resultM[] as true. Else
	}					 //store it as false.
}

/***********************************atLeastOne**************************************/
/*int atLeastOne(Customer *pCustomer, Trait *pTrait);                              */
/*Purpose:                                                                         */
/*	This funciton checks to see if the customer has at least one of the trait  */
/*	types and values that are queried.                                         */
/*Parameters:                                                                      */
/*	I	 *pCustomer        Customer pointer that is being checked for the  */
/*		                   queried Trait                                   */
/*	I 	 *pTrait           Trait pointer that is being queried             */
/*Notes:                                                                           */
/*	Needs a none null Trait pointer                                            */
/*	Needs a nono null Customer pointer                                         */
/*Returns:                                                                         */
/*	1	Found at least one Trait that matches the queried                  */
/*		one.                                                               */
/*	0	Could not find the Trait queried.                                  */
/***********************************************************************************/
int atLeastOne(Customer *pCustomer, Trait *pTrait)
{
	int i;
	//Iterate through the number of traits in the customer
	for(i = 0; i < pCustomer->iNumberOfTraits; i++)
	{
		//Check to see if you've found the correct trait type
		if(strcmp(pCustomer->traitM[i].szTraitType, pTrait->szTraitType)==0)
		{
			//Further check to see if it's the right trait value
			if(strcmp(pCustomer->traitM[i].szTraitValue, pTrait->szTraitValue)==0)
				return 1;
		}
	}
	return 0; //Looped through all traits and couldn't find it
}

/**********************************only**********************************/
/*Purpose:                                                              */
/*	Checks to see if the the Trait type queried is listed only once.*/
/*Parameters:                                                           */
/*	I	*pCustomer	Customer pointer that is being checked  */
/*				for the queried Trait type.             */
/*	I	*pTrait 	Trait pointer that is being queried     */
/*Notes:                                                                */
/*	Needs a none null Customer pointer                              */
/*	Needs a none null Trait pointer                                 */
/*Returns:                                                              */
/*	1	Found only one type of the Trait type                   */
/*		and Trait value that was queried.                       */
/*	0	Could not find that trait type and value or             */
/*		multples of the queried Trait type were                 */
/*		found                                                   */
/************************************************************************/
int only(Customer *pCustomer, Trait *pTrait)
{
	//Iteration variable, as well as a count of traitTypes that match queried trait type
	//Finally, a boolean to see if the exact type and value was found
	int i, iCount = 0, bFoundValue = 0;
	for(i = 0; i < pCustomer->iNumberOfTraits; i++)
	{
		if(strcmp(pCustomer->traitM[i].szTraitType, pTrait->szTraitType)==0)
		{
			iCount++; //Just found an instance of that trait type so add to the count.
			if(strcmp(pCustomer->traitM[i].szTraitValue, pTrait->szTraitValue)==0)
				bFoundValue = 1; //Just found the trait type and value, so indicate it
		}
	}

	if(iCount!=1) //Multiple instances of the same type were found, so false.
		return 0;
	if(!bFoundValue) //Couldn't find the type and value we were looking for, so false.
		return 0;
	
	return 1; //At this point it must be true.
}

/************************finalCheck***************************/
/*int finalCheck(Stack * stack)                              */
/*Purpose:                                                   */
/*	Takes a stack and checks it's only element (which    */
/*	should be a boolean)and returns that value.          */
/*Parameters:                                                */
/*	I	Stack * stack	Stack pointer that is to be  */
/*				evaluated                    */
/*Notes:                                                     */
/*	Stack pointer must be none null                      */
/*	Stack pionter must be a boolean                      */
/*Returns:                                                   */
/*	1	The first and only element value evaluates to*/
/*		true.                                        */
/*	0	The first and only element value evaluates to*/
/*		false.                                       */
/*************************************************************/
int finalCheck(Stack * stack)
{
	if(strcmp((*stack)->stackElementM[0].szBoolean, "1")==0) //At the end of the all the changing there will
		return 1;				     	 //be only one value left and it will
	else					      		 //be a boolean. If true, store it in resultM[] as true. Else
		return 0;				    	 //store it as false.
}

/****************************printCustomerData****************************
   Replace with a good function header. Please see my standards.  
   Also make the output look nice.  
   Advice:  Print a customer's info on a line followed on subsequent lines
   with indented traits.
   Example Output:
   ID         Customer Name
                   Trait      Value
   11111      BOB WIRE
                   GENDER     M
                   EXERCISE   BIKE
                   EXERCISE   HIKE
                   SMOKING    N
   22222      MELBA TOAST
                   GENDER     F
                   BOOK       COOKING
   33333      CRYSTAL BALL
                   SMOKING    N
                   GENDER     F
                   EXERCISE   JOG
                   EXERCISE   YOGA
********************************************************/
void printCustomerData(Customer customerM[], int iNumCustomer)
{
    int i;
    int j;
    // Print a heading for the list of customers and traits
    // printf("Needs a heading\n");
	printf("\n%-10sCustomer Name\n%-15sTrait%-6sValue\n", "ID", "","");
    for (i = 0; i < iNumCustomer; i++)
    {
        // Print the customer information
		printf("%-10s%s\n", customerM[i].szCustomerId, customerM[i].szCustomerName);
        // Print each of the traits
        for (j = 0; j < customerM[i].iNumberOfTraits; j++)
        {
            // Print a trait
			printf("%-15s%-11s%s\n", "", customerM[i].traitM[j].szTraitType, customerM[i].traitM[j].szTraitValue);

        }
    }
}
