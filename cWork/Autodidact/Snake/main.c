#include "data_display.h"

int main(int argc, char *argv[])
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    drawData(a,10);
    exit(0);
}

void drawData(int a[], int size)
{
    int i,k;
    for(i=0; i<size; i++) {
        for (k = 0; k < a[i]; k++) {
            printf("___");
        }
        printf("|\n");
    }
}
