#include <stdio.h>

#define LIMIT 10001

int prime(unsigned long long num);

int main(void)
{
    unsigned long long cnt = 0, num = 2;
    // Keep checking all numbers starting at 2
    // until you reach the LIMITth prime
    while(cnt < LIMIT)
    {
        if(prime(num))
            cnt++;
        num++;
    }

    // Subtract one, because you've gone over before the loop ends.
    num--;

    // Print the result.
    printf("%llu\n", num);
    return 0;
}

// Function to determine if the given number is prime
int prime(unsigned long long num)
{
    unsigned long long n = num, i;
    for(i = 2; i < n; i++)
        if(n % i == 0)
            return 0;
    return 1;
}
