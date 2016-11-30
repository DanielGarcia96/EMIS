#include <stdio.h>

#define TARGET 600851475143UL

unsigned long long prime(unsigned long long num);
void generate_prime_factors(unsigned long long A[], unsigned long long n, int len);

int main(void)
{
    return 0;
}

unsigned long long prime(unsigned long long num)
{
    unsigned long long n = num, i;
    for(i = 2; i < n; i++)
        if(n % i == 0)
            return i;
    return -1;
}

void generate_prime_factors(unsigned long long A[], unsigned long long n, int len)
{
    
}
