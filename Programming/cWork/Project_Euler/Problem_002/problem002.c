#include <stdio.h>

#define LIMIT 4000000

int main(void)
{
    int a = 1, b = 2, c = 3, sum = 2;
    while(c < LIMIT)
    {
        c = a+b;
        a = b;
        b = c;
        if(c % 2 == 0)
            sum+=c;
    }

    printf("%d\n", sum);
    return 0;
}
