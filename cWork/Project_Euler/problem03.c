#include <stdio.h>

#define NUMBER      600851475143

int isPrime(long long n);
long long highestFactor(long long n);

int main(void)
{
    printf("%lli\n", highestFactor(NUMBER));
    return 0;
}

int isPrime(long long n)
{
    long long i;
    for ( i = 2; i < n; i++ )
        if ( n % i == 0 )
            return 0;

    return 1;
}

long long highestFactor(long long n)
{
    long long i, multiple;
    for ( i = 2; i < n; i++ ) {
        if ( n % i == 0 )
        {
            multiple = n / i;
            int bM = isPrime(multiple);

            if ( bM ) {
                return multiple;
            }
        }
    }

    return 0;
}
