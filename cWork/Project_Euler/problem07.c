#include <stdio.h>

int isPrime(int n);

int main(void)
{
    int i = 2, count = 0;
    for ( ; ; i++) {
        if (isPrime(i))
            count++;
        if (count >= 10001)
            break;
    }
   
    printf("%d\n", i);
    return 0;
}

int isPrime(int n)
{
    int i;
    for ( i = 2; i < n; i++ ) {
        if ( n % i == 0 )
            return 0;
    }
    return 1;
}
