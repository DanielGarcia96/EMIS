#include <stdio.h>

#define LIMIT 1000

int main(void)
{
    int i, sum = 0;
    for( i = 0; i < LIMIT; i++)
        if(i % 3 == 0 || i % 5 == 0)
            sum += i;

    printf("%d\n", sum);
    return 0;
}
