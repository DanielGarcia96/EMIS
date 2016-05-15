#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define LIMIT 2000000

int isPrime(long long n);

int main(void)
{
    long long i, sum = 0;
    for ( i = 2; i < LIMIT; i++ )
        if ( isPrime(i) )
            sum += i;

    printf("%lli\n", sum);
    return 0;
}

int isPrime(long long n)
{
    long long i;
    for ( i = 2; i < n; i++)
        if ( n % i == 0)
            return 0;
    return 1;
}
