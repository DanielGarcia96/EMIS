#include <stdio.h>

long long divisor_sum(long long n);

int main(void)
{
    long long i, sum = 0;
    for(i=1; i<10000; i++)
    {
        long long one = divisor_sum(i);
        long long two = divisor_sum(one);
        if(i != one && two == i)
        {
            sum += one;
            sum += two;
        }
    }

    printf("%lli\n", sum/2);
    return 0;
}

long long divisor_sum(long long n)
{
    long long i, sum = 0;
    for(i=1; i<n; i++)
        if(n % i == 0)
            sum += i;
    return sum;
}
