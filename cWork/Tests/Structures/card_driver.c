#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"
#define DEBUG    0

int main(void)
{
    struct card hand[5];
    deal(hand);
    print_hand(hand);

    return 0;
}

void deal(struct card hand[])
{
    srand(time(NULL));

    int i;
    for(i=0; i < 5; ++i)
    {
        int roll = rand() % 12 ;

        if(DEBUG)
            printf("Roll was %d\n", roll);

        hand[i].pips = roll;
        if(roll < 4)
            hand[i].suit = 'S';
        else if(roll >= 4 && roll < 7)
            hand[i].suit = 'C';
        else if(roll >= 7 && roll < 10)
            hand[i].suit = 'D';
        else
            hand[i].suit = 'H';

        if(i != 0)
        {
            while(isRepeat(hand, i))
            {
                reroll(hand, i);
            }
        }
    }
}
int isRepeat(struct card hand[], int stopIndex)
{
    int i;
    for(i = 0; i < stopIndex; ++i)
    {
        if(hand[i].pips == hand[stopIndex].pips &&
           hand[i].suit == hand[stopIndex].suit)
               return 1;
    }
    return 0;
}

void reroll(struct card hand[], int targetIdx)
{
    int roll = rand() % 12 ;

    if(DEBUG)
        printf("Reroll was %d\n", roll);

    hand[targetIdx].pips = roll;

    if(roll < 4)
        hand[targetIdx].suit = 'S';
    else if(roll >= 4 && roll < 7)
        hand[targetIdx].suit = 'C';
    else if(roll >= 7 && roll < 10)
        hand[targetIdx].suit = 'D';
    else
        hand[targetIdx].suit = 'H';
}

void print_hand(struct card hand[])
{
   int i;
   for(i=0; i < 5; ++i)
    {
        if(DEBUG)
            printf("i = %d\nSuit is %c\nPip is %d\n", i, hand[i].suit, hand[i].pips);

	switch(hand[i].suit)
	{
	    case 'S':
		switch(hand[i].pips)
		{
		    case 10: printf("Jack of Spades\n");
			break;
		    case 11:
                        printf("Queen of Spades\n");
			break;
		    case 12:
                        printf("King of Spades\n");
			break;
		    case 0:
                        printf("Ace of  Spades\n");
			break;
		    default:
			printf("%d of Spades\n", hand[i].pips);
		}
	    break;
	    case 'C':
		switch(hand[i].pips)
		{
		    case 10:
			printf("Jack of Clubs\n");
			break;
		    case 11:
                        printf("Queen of Clubs\n");
			break;
		    case 12:
                        printf("King of Clubs\n"); 
			break;
		    case 0:
                        printf("Ace of Clubs\n"); 
			break;
		    default:
			printf("%d of Clubs\n", hand[i].pips);
		}
	    break;
	    case 'D':
		switch(hand[i].pips)
		{
		    case 10:
			printf("Jack of Diamonds\n"); 
			break;
		    case 11:
                        printf("Queen of Diamonds\n");
			break;
		    case 12:
                        printf("King of Diamonds\n");
			break;
		    case 0:
                        printf("Ace of Diamonds\n");
			break;
		    default:
			printf("%d of Diamonds\n", hand[i].pips);
		}
	    break;
	    case 'H':
		switch(hand[i].pips)
		{
		    case 10:
			printf("Jack of Hearts\n");
			break;
		    case 11:
                        printf("Queen of Hearts\n");
			break;
		    case 12:
                        printf("King of Hearts\n");
			break;
		    case 0:
                        printf("Ace of Hearts\n");
			break;
		    default:
			printf("%d of Hearts\n", hand[i].pips);
		}
	}
    } 
}
