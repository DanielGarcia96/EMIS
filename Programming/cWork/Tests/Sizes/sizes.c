#include <stdio.h>

#define MAX_DATA_SZ 500                     // Maximum size of sbData

typedef struct AllocNode
{
    short shAllocSize;                 // total size of the allocated item.  
                                       // This is negative for free nodes.
    short shRefCount;                  // The number of references to this allocated node.
    short shNodeType;                  // Node Type subscript.  
    char  sbData[MAX_DATA_SZ];         // This is the user's data in the node.  It might
                                       // be bigger than MAX_STRING.
} AllocNode;

int main(void)
{
   printf("Sizeof int: %lu\n", sizeof(unsigned));
   printf("Sizeof unsigned: %lu\n", sizeof(unsigned));
   printf("Sizeof long: %lu\n", sizeof(long));
   printf("Sizeof unsigned long: %lu\n", sizeof(unsigned long));
   printf("Sizeof long long: %lu\n", sizeof(long long));
   printf("Sizeof unsigned long long: %lu\n", sizeof(unsigned long long));
   printf("Sizeof char: %lu\n", sizeof(char));
   printf("Sizeof unsigned char: %lu\n", sizeof(unsigned char));
   printf("Sizeof float: %lu\n", sizeof(float));
   printf("Sizeof double: %lu\n", sizeof(double));
   printf("Sizeof long double: %lu\n", sizeof(long double));
   printf("Sizeof AllocNode: %lu\n", sizeof(AllocNode));
   return 0;
}
