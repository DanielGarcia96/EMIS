/****************************************************
cs2123p1.c by Daniel Kane Garcia
Purpose:
	Convert infix queries to postfix queries.
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
	Must link with cs2123p1Driver.o/exe in order
	to use any function associated with these
	structs.
****************************************************/
#include "cs2123p1.h"

//function prototype for main processing of infix input
int convertToPostFix(char * pszInfix, Out out);

//function prototype for right parenthesis handling
int isGoodRParen(Stack * stack, Out * out);

//function prototype for operator handling
void isOperator(Stack * stack, Out * out, Element * element);

//function prototype for the end of tokens processing
int endTokens(Stack * stack, Out * out);

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
	Stack stack = newStack();	/*Create a stack for element manipulation*/
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
		{
			//If it's an operand, add it to the out
			addOut(out, element);
		}
		else if(element.iCategory == CAT_LPAREN)
		{
			//If it's a left parenthesis, push it on to the stack
			push(stack, element);
		}
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
		{
			isOperator(&stack, &out, &element);
		}
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
		{
			break;
		}
		else if((*element).iPrecedence > TopElement.iPrecedence)
		{
			break;
		}
		else
		{
			addOut(*out,pop(*stack));
		}
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
