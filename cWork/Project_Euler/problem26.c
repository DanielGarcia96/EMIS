#include <stdio.h>

#define STOP  1000
#define A_BUF 256

unsigned cal_cycle(long double n, unsigned denominator);
int is_repeat(int a[], unsigned len, int d);

int main(void)  {
   unsigned highest = 1;
   unsigned cur_cycle = 0;
   long double hold = 0;
   long double start = 2;
   while ( start < STOP )  {
      hold = 1/start;
      cur_cycle = cal_cycle(hold, start);
      if ( highest < cur_cycle )
         highest = cur_cycle;
      start++;
   }

   printf("%u\n", highest);
   return 0;
}

unsigned cal_cycle(long double n, unsigned denominator)  {
   long double num = n;
   int a[A_BUF];
   unsigned len = 0;

   //printf("Calculating 1/%d\n", denominator);
   
   while ( num > 0 && len < A_BUF )  {
      num *= 10;
      int cur_d = (int) num % 10;
      if ( is_repeat(a, len, cur_d) )
         return len;
      //printf("cur_d = %d\n", cur_d);
      a[len] = cur_d;
      len++;
      num -= cur_d;
      //printf("%lf\n", num);
   }

   return len;
}

int contains_slice(int a[], unsigned len, int a, int b)  {
   int i;
   for ( i = 0; i < len; i++ )
      if ( a[i] == d )
         return 1;

   return 0;
}
