#include <stdio.h>

int main(void)
{
    int i, sum = 0, ssum = 0;
    for ( i = 1; i <= 100; i++ ) {
        sum += i;
        ssum += i * i;
    }
    printf("%d\n", (ssum > (sum*sum)) ? ssum-(sum*sum) : (sum*sum) - ssum);
    return 0;
}
