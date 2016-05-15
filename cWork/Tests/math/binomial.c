#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long int factorial(int n);
void calcEx(int exp, int coA, int coB);
long int calcBi(int n, int k);

int main(int argc, char *argv[])
{
    printf("%ld\n", calcBi(20,4));
    return 0;
}

long int factorial(int n)
{
    long int product = 1;
    int i;
    for(i = (int)n; i > 1; i--)
        product *= i;

    return product;
}

void calcEx(int exp, int coA, int coB)
{
    printf("%dx^(%d)%dy^(0)\n", coA, exp, coB);
    int i;
    for(i=1; i<exp; i++)
    {
        printf("%ld(%dx^(%d)%dy^(%d))\n", calcBi(exp,i), coA, exp-i, coB, i);
    }
}

long int calcBi(int n, int k)
{
    if ( k == 0 || n == 0 )
        return 1;
    return factorial(n)/(factorial(n-k)*factorial(k));
}
