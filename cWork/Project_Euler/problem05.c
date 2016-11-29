#include <stdio.h>

int main(void)
{
    int i, count = 1;
    while ( 1 ) {
        int bad = 0;
        for ( i = 1; i <= 20; i++ ) {
            if ( count % i != 0 ) {
                bad = 1;
                break;
            }
        }
        if (!bad)
            break;
 
        count++;
    }

    printf("%d\n", count);
    return 0;
}
