#include <stdio.h>

int highestPal();
int digitLength(int n);
int isPal(int n);

int main(void)
{
    printf("%d\n", highestPal());
    return 0;
}

int highestPal()
{
    int i,k, highest = 0;
    for(i = 999; i > 99; i--){
        for(k = 999; k > 99; k--){
            int curpro = k*i;
            if (isPal(i*k) && curpro > highest)
                highest = curpro;
        }
    }
    return highest;
}

int digitLength(int n)
{
    int length = 0;
    while (n > 0) {
        length++;
        n /= 10;
    }

    return length;
}

int isPal(int n)
{
    int i,k,length = digitLength(n);
    for ( i = 0; i < length; i++ ) {
        int back = n, front = n;
        for ( k = 0; k < (length-i)-1; k++ )
            back /= 10;
        for ( k = 0; k < i; k++ )
            front /= 10;
        if ( (front % 10) != (back % 10) )
            return 0;
    }
    return 1;
}
