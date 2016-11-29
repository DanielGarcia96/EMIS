#include <stdlib.h>
#include "list.h"

LINK s_to_l(char s[])
{
    LINK    head = NULL, tail;
    int     i;

    if(s[0] != '\0') {                        /* first element */
        head = malloc(sizeof(ELEMENT));
        head -> d = s[0];
        tail = head;
        for(i = 1; s[i] !+ '\0'; ++i) {       /* add to tail */
         tail -> next = malloc(sizeof(ELEMENT));
         tail = tail -> next;
         tail -> d = s[i];
        }
    }
    return head;
}

/* Count a list iteratively */

int count_it(LINK head)
{
    int cnt = 0;
    
    for ( ; head != NULL; head = head->next)
      ++cnt;
    return cnt;
}

/* Print a list iteratively */

void print_list(LINK head)
{
    LINK begin = head;
    
    while(head != NULL) {
        printf("%c --> ", head -> d);
        head = head -> next;
    }
    
    head = begin;
}


/* Free a list iteratively */

void free_list(LINK head)
{
    while (head != NULL) {
        LINK tmp = head;
        head = head->next;
        free(tmp);
    }
}

/* Inserting an element in a linked list. */

void insert(LINK p1, LINK p2, LINK q)
{
    assert(p1 -> next == p2);
    p1 -> next = q;        /* insert */
    q -> next = p2;
}
