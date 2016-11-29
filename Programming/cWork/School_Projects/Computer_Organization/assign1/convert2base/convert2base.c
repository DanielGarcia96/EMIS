#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 256

void convert2base(char base[], char arg[]);
int  count_digits(unsigned long long n);
void reverse_str(char str[], int len);

int main(int argc, char *argv[])  {
   printf("Daniel Garcia\n");
   if ( argc < 3 )  {
      fprintf(stderr, "Usage: %s <base> <decimal number>\n", argv[0]);
      return 0;
   }

   convert2base(argv[1], argv[2]);
   
   return 0;
}

void convert2base(char base[], char arg[])  {
   int b = atoi(base);
   char buffer[BUF];
   int idx = 0;
   unsigned long long n = atol(arg);
   int offset1 = count_digits(n);
   int offset2 = count_digits(n/b) + 
                 count_digits((unsigned long long) b) +
                 count_digits(n%b) + 6;
   char res[BUF];

   while ( n > 0 )  {
      char digit;
      if ( n%b > 9)  {
         digit = (n%b-10) + 'A';
      }
      else
         digit = (n%b) + '0';

      res[idx] = digit;
      idx++;

      sprintf(buffer, "%llu * %d + %llu", n/b, b, n%b);
      printf("%*llu = %-*s (%c)\n", offset1, n, offset2, buffer, digit);
      n /= b;
   }

   reverse_str(res, idx);
   res[idx] = '\0';

   printf("%s\n", res);
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
