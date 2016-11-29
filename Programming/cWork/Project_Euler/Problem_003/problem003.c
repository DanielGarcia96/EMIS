#include <stdio.h>

#define FACTOR 1000000
#define TARGET 600851475143UL

unsigned long is_prime(unsigned long n);
unsigned long in_list(const unsigned long A[], const unsigned long key, const unsigned long len);
unsigned long insert(unsigned long A[], unsigned long key, unsigned long *len);
unsigned long factors(unsigned long A[], unsigned long n, unsigned long *len);
void print_list(unsigned long A[], unsigned long len);

int main(void)
{
    // Create my list
    unsigned long A[100] = {1};
    unsigned long p = 1;
    unsigned long *len = &p;

    // Find all my factors
    factors(A, TARGET, len);

    //print_list(A, *len);

    // Print the final result
    printf("%lu\n", A[*len-2]);
    return 0;
}

unsigned long is_prime(unsigned long n)
{
    // If the number is not divisible by anything but
    // itself and 1, it's prime, otherwise return what it's
    // divisible by.
    unsigned long num = n, i;
    for(i = 2; i < num; i++)
        if(num % i == 0)
            return i;
    return 0;
}

// simple binary search
unsigned long in_list(const unsigned long A[], const unsigned long key, const unsigned long len)
{
    // If we've reached the last element in the list
    // then this is either the element we're looking for
    // or it's not in the list.
    if(len == 1 && A[0] == key)
        return 1;
    else if(len == 1)
        return 0;

    // If the element we're looking for is below the middle value,
    // then we search the lower values.
    // Otherwise, we search the upper values.
    if(key < A[len / 2])
        return in_list(A, key, len / 2);
    else
        return in_list(A + len / 2, key, len / 2);
}

unsigned long insert(unsigned long A[], unsigned long key, unsigned long *len)
{
    // Start at the top of the list.
    // For every value greater than the key,
    // we move lower and lower.
    unsigned long i;
    for(i = *len - 2; i > -1 && A[i] > key; i--)
        A[i + 1] = A[i];

    // When we've reached the appropriate position,
    // we insert the key, and increase the length
    A[i+1] = key;
    *len += 1;
    return 0;
}

unsigned long factors(unsigned long A[], unsigned long n, unsigned long *len)
{
    // If the given number is prime, we've reached the final prime factor.
    unsigned long fact = is_prime(n);
    if (!fact)
    {
        // If that factor is not in the list, insert it there.
        insert(A, n, len);
        // Terminate
        return 0;
    }

    // Otherwise, insert the factor if it's prime and 
    // move on to the remaining factor.
    if(!is_prime(fact))
        insert(A, fact, len);

    return factors(A, n/fact, len);
}

void print_list(unsigned long A[], unsigned long len)
{
    unsigned long l = len, i;
    for(i = 0; i < l; i++)
        printf("%lu ", A[i]);
    printf("\n");
}
