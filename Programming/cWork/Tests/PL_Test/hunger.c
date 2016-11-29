#include <stdio.h>
#include <string.h>
#include "functions.h"

char katniss[] = "Jennifer Lawrence";
static char peeta[] = "Josh Hutcherson";
void panem()
{
   int iCountDown = 10;
   char szContestant[30];
   strcpy(szContestant, katniss);
   district12(szContestant);
   strcpy(szContestant, peeta);
   district12(szContestant);
   printf("panem: %d\n", iCountDown);
}
