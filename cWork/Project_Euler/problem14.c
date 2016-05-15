#include <stdio.h>
#include <stdlib.h>

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
    while(start != 1){
        if(start%2)
            start /= 2;
        else
            start = (3*start) + 1;
        count++;
    }

    return count;
}
