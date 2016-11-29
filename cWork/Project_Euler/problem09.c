#include <stdio.h>
#include <math.h>

#ifdef  LIMIT
#undef  LIMIT
#endif  

#define LIMIT    1000

int main(void)
{
    long double a, b, c;
    for ( a = 1; a < LIMIT; a++ ) {
        int found = 0;
        for ( b = a+1; b < LIMIT; b++ ) {
            c = sqrt((a*a) + (b*b));
            if ( c > a && c > b && (a+b+c) == 1000 ) {
                printf("%Lf %Lf %Lf\n", a, b, c);
                found = 1;
                break;
            }
        }
        if ( found )
            break;
    }
   
    printf("%Lf\n", a*b*c);
    return 0;
}
