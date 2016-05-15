#include <stdio.h>

#define LIMIT  100

long even_fibonacci(long seed);

int main(void)
{
    printf("%ld\n", even_fibonacci(LIMIT));
    return 0;
}

long even_fibonacci(long seed)
{
    long sum = 0;
    long a = 0;
    long b = 1;

    while (seed-- > 1) {
        long t = 0;
        t = a;
        a = b;
        b += t;

        if ( b >= 4000000 || a >= 4000000 )
            break;

        if ( b % 2 == 0 )
            sum += b;
    }

    return sum;
}
