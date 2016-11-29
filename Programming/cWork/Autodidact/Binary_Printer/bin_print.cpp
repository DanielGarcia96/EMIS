#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void bin_num(int n);

int main(int argc, char *argv[])  {
   if ( argc < 2 ) {
      fprintf(stderr, "Please provide number(s) in decimal\n");
      return 1;
   }

   int i;
   for ( i = 1; i < argc; i++ )
      bin_num( atoi(argv[i]) );
   return 0;
}

void bin_num(int n)  {
   int i = 0;
   int mask = INT_MAX;
   mask = ~mask;
   unsigned num = (unsigned) n;
   
   while(num > 0)  {
      i++;
      if ( mask & num )
         printf("1");
      else
         printf("0");

      if ( i != 0 && i % CHAR_BIT == 0 )
         printf(" ");

      num <<= 1;     
   }

   for ( ; i<sizeof(int)*CHAR_BIT; i++ )  {
      printf("0");
      if ( i != 0 && i % CHAR_BIT == 0 )
         printf(" ");
   }
   printf("\n");
}
