#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.> #include "poker.h"

#define  DEBUG    0

int roundWin(card communityCards[], int players, ...)
{
    va_list playerHands;
    va_start(playerHands, players);

    int i, highestHand = 0, playerIdx = -1;
    for(i=0; i<players; ++i)
    {
        card player[] = va_arg(playerHands, card[]);

        int k;
        for(k=0; k<5; ++k)
        {
            
        }
    }

    va_end(playerHands);
    return playerIdx;
}

void addToLineUp(card *communityCards)
{
    
}

void deal(card hand[], deck mainDeck)
{
    srand(time(NULL));

    int i;
    for(i=0; i < 5; ++i)
    {
        int roll = roll();

        if(DEBUG)
            printf("Roll was %d\n", roll);
        
        while(mainDeck.allCards[roll].dealt != 'Y')
            roll = roll();

        hand[i] = mainDeck.allCards[roll];
        mainDeck.allCards[roll].dealt = 'N';
    }
}

void printHand(card hand[])
{
   int i;
   for(i=0; i < 5; ++i)
    {
        if(DEBUG)
            printf("Pip: %d, Suit %c, Dealt %c\n", hand[i].pips, hand[i].suit, hand[i].dealt);

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

void loadDeck(deck dk)
{
    dk[0] = {1,'S','N'};
    dk[1] = {2,'S','N'};
    dk[2] = {3,'S','N'};
    dk[3] = {4,'S','N'}; 
    dk[4] = {5,'S','N'};
    dk[5] = {6,'S','N'};
    dk[6] = {7,'S','N'};
    dk[7] = {8,'S','N'}; 
    dk[8] = {9,'S','N'};
    dk[9] = {10,'S','N'};
    dk[10] = {11,'S','N'};
    dk[11] = {12,'S','N'}; 
    dk[12] = {13,'S','N'};
    dk[13] = {14,'S','N'};
    dk[14] = {1,'C','N'};
    dk[15] = {2,'C','N'}; 
    dk[16] = {3,'C','N'};
    dk[17] = {4,'C','N'};
    dk[18] = {5,'C','N'};
    dk[19] = {6,'C','N'}; 
    dk[20] = {7,'C','N'};
    dk[21] = {8,'C','N'};
    dk[22] = {9,'C','N'};
    dk[23] = {10,'C','N'};
    dk[24] = {11,'C','N'};
    dk[25] = {12,'C','N'};
    dk[26] = {13,'C','N'};
    dk[27] = {14,'C','N'};
    dk[28] = {1,'D','N'};
    dk[29] = {2,'D','N'};
    dk[30] = {3,'D','N'};
    dk[31] = {4,'D','N'}; 
    dk[32] = {5,'D','N'};
    dk[33] = {6,'D','N'};
    dk[34] = {7,'D','N'};
    dk[35] = {8,'D','N'}; 
    dk[36] = {9,'D','N'};
    dk[37] = {10,'D','N'}; 
    dk[38] = {11,'D','N'};
    dk[39] = {12,'D','N'}; 
    dk[40] = {13,'D','N'};
    dk[41] = {14,'D','N'};
    dk[42] = {1,'H','N'};
    dk[43] = {2,'H','N'};
    dk[44] = {3,'H','N'};
    dk[45] = {4,'H','N'};
    dk[46] = {5,'H','N'};
    dk[47] = {6,'H','N'}; 
    dk[48] = {7,'H','N'};
    dk[49] = {8,'H','N'};
    dk[50] = {9,'H','N'};
    dk[51] = {10,'H','N'}; 
    dk[52] = {11,'H','N'};
    dk[53] = {12,'H','N'};
    dk[54] = {13,'H','N'};
    dk[55] = {14,'H','N'};
}
