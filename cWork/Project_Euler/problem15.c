#include <stdio.h>
#include <stdlib.h>

void fillArray(int *array, int start, int end, int val);
void printArray(int *array, int size);
unsigned long long calcPaths(int *array, int size);
int checkEnd(int *array, int size);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <number-of-grid-squares>\n", argv[0]);
        return -1;
    }
    int n = atoi(argv[1]);
    int *array = (int *) malloc(sizeof(int)*n);

    fillArray(array, 0, n, 1);

    printf("%llu\n", calcPaths(array, n));

    free(array);
    return 0;
}


void fillArray(int *array, int start, int end, int val)
{
    int i;
    for ( i = start; i<end; i++ )
        *(array+i) = val;
}

unsigned long long calcPaths(int *array, int size)
{
    int i;
    unsigned long long sum = 0;
    for(i = 0; i < size; i++)
    {
        int k;
        for(k = size-1; k >= 0; k--)
        {
            if(*(array+k) == size+1)
                continue;
            else
            {
                *(array+k) = *(array+k) + 1;
                fillArray(array, k+1, size, *(array+k));
                sum++;
                i--;
                break;
            }
        }
        if(checkEnd(array, size))
            return 0;
    } 
    return sum;
}

int checkEnd(int *array, int size)
{
    int i, count = 0;
    for (i = 0; i < size; i++)
    {
        if(*(array+size) == size+1)
            count++;
    }

    return (count == size) ? 1 : 0;
}


void printArray(int *array, int size)
{
    printf("[ ");

    int i;
    for( i = 0; i < size; i++)
    {
        printf("%d ", *(array+i));
    }

    printf("]\n");
}
