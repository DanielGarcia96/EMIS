#include <stdio.h>

int main(void)
{
    int a[200];
    int length = 1, carry = 0, i, idx = 0, acumultr;
    a[0]=1;
    for(i=1;i<=100;i++)
    {
        for(idx=0; idx<length; idx++)
        {
            acumultr = a[idx]*i+carry;
            a[idx] = acumultr%10;
            carry = acumultr/10;
        }
        while(carry>0)
        {    
            a[length] = carry%10;
            carry = carry/10;
            length++;
        }
    }

    long long sum = 0;
    for(i=length-1;i>=0;i--)
        sum += a[i];
    printf("%lli\n", sum);
    return 0;
}
