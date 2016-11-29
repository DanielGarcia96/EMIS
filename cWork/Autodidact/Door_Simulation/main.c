#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG  0

int main(void)
{
    srand(time(NULL));
    int doors[3], wins = 0, losses = 0, rounds;
    int i;

    printf("Amount of rounds: ");
    scanf("%d", &rounds);

    for(i=0; i<rounds; ++i)
    {
        int car = rand() % 3;
        doors[car] = 1;
        int choice = rand() % 3;

        if(DEBUG)
        {
            printf("door[0] = %d, door[1] = %d, door[2] = %d\n", doors[0], doors[1], doors[2]);
            printf("\tFinal Choice = %d\n", choice);
        }
        
        if(doors[choice])
            ++wins; 
        else
            ++losses;

        doors[0] = doors[1] = doors[2] = 0;
    }

    printf("Same door strategy:\n");
    printf("Wins: %d\n", wins);
    printf("Losses: %d\n", losses);

    wins = losses = 0;

    for(i=0; i<rounds; ++i)
    {
        int car = rand() % 3;
        doors[car] = 1;
        
        int choice = rand() % 3;
        int first_choice = choice;

        if(choice == 0)
        {
            if(!doors[1])
               choice = 2;
            else
               choice = 1;
        }
        else if(choice == 1)
        {
            if(!doors[0])
               choice = 2;
            else
               choice = 0;
        }
        else
        {
            if(!doors[2])
               choice = 2;
            else
               choice = 0;
        }
        
        if(doors[choice])
            ++wins; 
        else
            ++losses;

        if(DEBUG)
        {
            printf("door[0] = %d, door[1] = %d, door[2] = %d\n", doors[0], doors[1], doors[2]);
            printf("\tFirst Choice = %d\n", first_choice);
            printf("\tFinal Choice = %d\n", choice);
        }

        doors[0] = doors[1] = doors[2] = 0;
    }

    printf("Change door strategy:\n");
    printf("Wins: %d\n", wins);
    printf("Losses: %d\n", losses);

    return 0;
}
