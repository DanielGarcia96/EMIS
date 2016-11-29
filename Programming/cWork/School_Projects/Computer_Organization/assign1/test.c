#include <stdio.h>

void bit_print(unsigned n);

int main(void)  {
   unsigned x = 4;
   unsigned mask = 1;
   unsigned n = 37;
   unsigned a = x;
   while ( n > 0 )  {
      x = x << 1;
      n = n >> 1;
      if ( n & mask )
         a += x;
   }

   printf("%u\n", a);
   return 0;
}

void bit_print(unsigned n)  {
   unsigned mask = 2147483648;
   unsigned num = n;
   unsigned short count = 0;

   while ( count < 32 )  {
      if ( count % 4 == 0 && count != 0 )
         printf(" ");
      if ( mask & num )
         printf("1");
      else
         printf("0");
      num = num << 1;
      count++;
   }
   printf("\n");
}
