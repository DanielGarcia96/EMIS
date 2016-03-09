#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    char byteMap;
    struct LLimp *next;
} LLimp;

typedef LLimp *LL;


LL allocateList(char byteInfo);
void LLadd(LL list, char nextByte);
void LLremove(LL list, int index, char searchByte);
void LLinsert(LL list, int index, char nextByte);
void displayNode(LL list, int index, char searchByte);
void displayList(LL list);
void freeList(LL list);
void bit_print(char printByte);
