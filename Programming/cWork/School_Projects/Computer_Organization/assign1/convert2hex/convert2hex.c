#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 256

void convert2hex(char arg[]);
int  count_digits(unsigned long long n);
void reverse_str(char str[], int len);

int main(int argc, char *argv[])  {
   printf("Daniel Garcia\n");
   if ( argc < 2 )  {
      fprintf(stderr, "Usage: %s <decimal number>\n", argv[0]);
      return 0;
   }

   convert2hex(argv[1]);
   
   return 0;
}

void convert2hex(char arg[])  {
   char buffer[BUF];
   int idx = 0;
   unsigned long long n = atol(arg);
   int offset1 = count_digits(n);
   int offset2 = count_digits(n/16) + 8 + count_digits(n%16);
   char res[BUF];

   while ( n > 0 )  {
      char digit;
      if ( (n%16) > 9 )  {
         digit = (n%16-10) + 'A';
      }
      else
         digit = (n%16) + '0';

      res[idx] = digit;
      idx++;

      sprintf(buffer, "%llu * 16 + %llu", n/16, n%16);
      printf("%*llu = %-*s (%c)\n", offset1, n, offset2, buffer, digit);
      n /= 16;
   }

   reverse_str(res, idx);
   res[idx] = '\0';

   printf("0x%s\n", res);
}

void reverse_str(char str[], int len)  {
   int i;
   for ( i = len - 1; i >= len/2; i-- )  {
      char tmp = str[i];
      str[i] = str[(len-1)-i];
      str[(len-1)-i] = tmp;
   }
}

int count_digits(unsigned long long n)  {
   int count = 0;
   unsigned long long num = n;
   while ( num > 0 )  {
      count++;
      num /= 10;
   }

   return count;
}
