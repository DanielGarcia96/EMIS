#include <stdio.h>
#include <math.h>

#define LIMIT 100

// Trivial
int main(void)
{
    int i;
    unsigned long long sumsquare = 0, squaresum = 0;
    for(i = 1; i <= 100; i++)
    {
        sumsquare += (unsigned long long) pow((double) i, 2);
        squaresum += i;
    }

    squaresum *= squaresum;
    printf("%llu\n", squaresum-sumsquare);
    return 0;
}
