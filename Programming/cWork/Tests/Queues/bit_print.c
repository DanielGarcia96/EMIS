#include "bit_include.h"

/**************bit_print****************
Algorithm:
    Use a single high order bit and
    move all bits of subject number
    past this bit and 'and' them to 
    check if there is a 1 or 0 there.
***************************************/
void bit_print(int a)
{
    int    i;                            /* Counting Variable */
    int    n = sizeof(int) *CHAR_BIT;    /* Size of a byte stored in CHAR_BIT, in limits.h */
    int    mask = 1 << (n - 1);          /* mask = 100...0 */ 

    for (i = 1; i <= n; ++i)
    {
        putchar(((a & mask) == 0) ? '0' : '1');
        a <<= 1;
        if (i % CHAR_BIT == 0 && i < n)
            putchar(' ');
    }

    putchar('\n');
}
