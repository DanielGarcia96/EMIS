#include <stdlib.h>
#include "list.h"

/* Recursively generates a linked list based on a string */

LINK string_to_list(char s[])
{
    LINK    head;

    if (s[0] == '\0')    /* base case */
       return NULL;
    else {
       head = malloc(sizeof(ELEMENT));
       head -> d = s[0];
       head -> next = string_to_list(s + 1);
       return head;
    }
}

/* Count a list recursively */

int count(LINK head)
{
    if (head == NULL)
       return 0;
    else
       return (1 + count(head -> next));
}

/* Print a list recursively */

void print_list(LINK head)
{
   if (head == NULL)
      printf("NULL");
   else {
      printf("%c --> ", head -> d);
      print_list(head -> next);
   }
}

/* Recursively free a list */

void free_list(LINK head)
{
    if(head == NULL)
        return;
    else {
        free_list(head->next);
        free(head);
    }
}

/* Concatenate list a and b with a as head. */

void concatenate(LINK a, LINK b)
{
    assert(a != NULL);
    if (a -> next == NULL)
       a -> next = b;
    else
       concatenate(a -> next, b);
}
