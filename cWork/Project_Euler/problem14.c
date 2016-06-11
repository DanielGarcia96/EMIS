#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int countCollatz(int start);

int main(int argc, char *argv[])
{
    int start = 1000000, highest = 0, hstart = start;
    while(start >= 1){
        int hold = countCollatz(start);
        if(hold > highest){
            highest = hold;
            hstart = start;
        }
        start--;
    }

    printf("%d\n", hstart);
    return 0;
}

int countCollatz(int start)
{
    int count = 0;
    long long rstart = start;
    while(rstart > 1){
        if(rstart % 2 == 1)
            rstart = (3 * rstart) + 1;
        else
            rstart =  rstart/2;
        count++;
    }
    return count;
}
