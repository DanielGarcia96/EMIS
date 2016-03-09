#include <stdio.h>
#include <stdlib.h>
#include "list.h"

LL allocateList(char byteInfo)
{
    LL list = (LL) malloc(sizeof(LLimp));
    list->byteMap = byteInfo;
    list->next = NULL;
    return list;
}

void LLadd(LL list, char nextByte)
{
    LL start = list; 
    while(list->next != NULL)
        list = (LL) list->next;

    list->next = (struct LLimp*) malloc(sizeof(LLimp));
    list = (LL) list->next;
    list->byteMap = nextByte;
    list->next = NULL;

    list = start;
}

void LLremove(LL list, int index, char searchByte)
{
    if(index == -1)
    {
        int foundByte = list->byteMap == searchByte;
        LL start = list;
        while(list->next != NULL)
        {
            LL nextNode = (LL) list->next;
            if(searchByte == nextNode->byteMap)
            {
                foundByte = 1;
                break;
            } 
            list = (LL) list->next;
        } 

        if(foundByte)
        {
            LL nextNode = (LL) list->next;
            if(nextNode == NULL)
            {
                free(list);
                return;
            }
            else if(nextNode->next == NULL)
            {
                free(list->next);
            }
            else
            {
                LL tmp = (LL) list->next;
                list->next = tmp->next;
                free(tmp);
            }
        }

        list = start;
    } 
    else
    {
        int foundByte = index == 0;
        LL start = list;
        while(list->next != NULL)
        {
            --index;
            if(index == 0)
            {
                foundByte = 1;
                break;
            } 
            list = (LL) list->next;
        } 

        if(foundByte)
        {
            LL nextNode = (LL) list->next;
            if(list->next == NULL)
            {
                free(list);
                return;
            }
            else if(nextNode->next == NULL)
            {
                free(list->next);
            }
            else
            {
                LL tmp = (LL) list->next;
                list->next = tmp->next;
                free(tmp);
            }
        }
        else
            printf("Node does not exist\n");

        list = start;
    }
}

void LLinsert(LL list, int index, char nextByte)
{
        int foundByte = index == 0;
        LL start = list;
        while(list->next != NULL)
        {
            --index;
            if(index == 0)
            {
                foundByte = 1;
                break;
            } 
            list = (LL) list->next;
        } 

        if(foundByte)
        {
            LL nextNode = (LL) list->next;
            if(nextNode == NULL)
            {
                list->next = (struct LLimp *) allocateList(nextByte); 
            }
            else if(nextNode->next == NULL)
            {
                list = (LL) nextNode;
                list->next = (struct LLimp *) allocateList(nextByte);
            }
            else
            {
                LL tmp = allocateList(nextByte);
                tmp->next = list->next;
                list->next = (struct LLimp*) tmp;
            }
        }
        else
            printf("Nodes does not exist\n");

        list = start;
}

void displayNode(LL list, int index, char searchByte)
{
    LL start = list;
    if(index == -1)
    {
        while(list != NULL)
        {
            if(searchByte == list->byteMap)
                break;
            list = (LL) list->next;
        }

        printf("%c = ", list->byteMap);
        bit_print(list->byteMap);
    }
    else
    {
         while(list != NULL)
         {
             if(index <= 0)
                 break;
             --index;
             list = (LL) list->next;
         }

         if(list != NULL)
         {
             printf("%c = ", list->byteMap);
             bit_print(list->byteMap);
         }
         else
             printf("Node does not exist\n\n");
    }

    list = start;
}

void displayList(LL list)
{
    LL start = list;
    while(list != NULL)
    {
        printf("%c = ", list->byteMap);
        bit_print(list->byteMap);
        list = (LL) list->next;
    } 

    list = start;
}

void bit_print(char printByte)
{
    int i;
    int byteSize = sizeof(char) * CHAR_BIT;
    int mask = -256;

    for(i=0; i<byteSize; i++)
    {
        putchar(((printByte & mask) == 0) ? '0' : '1');
        printByte <<= 1;
    }

    putchar('\n');
}

void freeList(LL list)
{
    while(list != NULL)
    {
        LL tmp = list;
        list = (LL) list->next;
        free(tmp);
    }
}
