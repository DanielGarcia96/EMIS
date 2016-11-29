#include <stdio.h>

int dCount(long long n);
long long calcTri(int idx);

int main(void)
{
    long long val = calcTri(1);
    int i = 1, dVal = dCount(val);
    while(dVal <= 500)
    {
        i++;
        val = calcTri(i);
        dVal = dCount(val);
    }

    printf("%lli\n", val);
    return 0;
}

long long calcTri(int idx)
{
    int i;
    long long res = 0;
    for(i=1; i <= idx; i++)
        res+=i;
    return res;
}

int dCount(long long n)
{
    int count = 1;
    long long i;
    for(i=2; i<n; i++)
        if(n%i == 0)
            count++;

    return count;
}
