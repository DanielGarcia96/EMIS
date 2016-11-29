#include <stdio.h>
#include "functions.h"

// games.c
extern char katniss[];
extern char peeta[];
void district12(char szOneContestant[])  {
   int iCountDown = 20;
   static int iPenalty = 10;
   iCountDown--;
   iPenalty += 5;
   printf("district12: %s\n", szOneContestant);
   printf("district12: %d %d\n"
           , iCountDown, iPenalty);
}
