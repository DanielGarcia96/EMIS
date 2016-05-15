#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int i = 0;
    char nums[100][51];
    unsigned long long sum = 0, cur;
    FILE *fp = fopen("numbers", "r");
    char buffer[52];
    
    while(fgets(buffer, 52, fp) != NULL)
    {
        strcpy(nums[i], buffer);
        nums[i][50] = '\0';
        printf("%s\n", nums[i]);
        i++;
    }
    fclose(fp);

    for(i = 0; i<100; i++)
    {
        cur = atoll(nums[i]);
        printf("atoll == %llu\n", cur);
        sum += cur;
    }

    printf("%llu\n", sum);

    return 0;
}
