#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER   128

void convert2dec(char str_num[], char dec[]);
void convert2hex(char str_num[], char hex[]);
int m_power(int base, int exp);
void nCopy(char dest[], char src[], size_t start, size_t stop);
void str_reverse(char src[], int length);

int main(int argc, char *argv[])  {
   if ( argc < 2 ) {
       printf("Daniel Garcia\nUsage: %s <hex/decimal integer>\n", argv[0]);
       return -1;
   }

   char dec[BUFFER] = "";
   char hex[BUFFER] = "";
   
   convert2hex(argv[1], hex);
   convert2dec(argv[1], dec);

   printf("Daniel Garcia\n%s %s\n", dec, hex);

   return 0;
}

void convert2hex(char str_num[], char hex[])  {
   int hex_c;
   int hex_d;
   int i;
   int len = strlen(str_num);
   int length = 0;

   if(len > 2 && str_num[1] == 'x')  {
      nCopy(hex, str_num, 2, len);
      return;
   }
   
   i = 0;
   hex_d = atoi(str_num);
   while ( hex_d > 0 )  {
      hex_c = hex_d % 16;
      switch ( hex_c ) {
         case 10:
             hex[i] = 'A';
         break;
         case 11:
             hex[i] = 'B';
         break;
         case 12:
             hex[i] = 'C';
         break;
         case 13:
             hex[i] = 'D';
         break;
         case 14:
             hex[i] = 'E';
         break;
         case 15:
             hex[i] = 'F';
         break;
         default:
             hex[i] = '0' + hex_c;
      }
      hex_d /= 16;
      length++;
      i++;
   }

   str_reverse(hex, length);
   hex[length] = '\0';
}

void convert2dec(char str_num[], char dec[])  {
   int carry = 0;
   int i;
   int len = strlen(str_num);
   int length = 0;

   if(len > 2 && str_num[1] != 'x')  {
      strcpy(dec, str_num);
      return;
   }
   
   for ( i = 0; i < len-2; i++ )  {
      switch ( str_num[len - 1 - i] )  {
         case 'A':
         case 'a':
            carry += 10 * m_power(16, i);
         break;
         case 'B':
         case 'b':
            carry += 11 * m_power(16, i);
         break;
         case 'C':
         case 'c':
            carry += 12 * m_power(16, i);
         break;
         case 'D':
         case 'd':
            carry += 13 * m_power(16, i);
         break;
         case 'E':
         case 'e':
            carry += 14 * m_power(16, i);
         break;
         case 'F':
         case 'f':
            carry += 15 * m_power(16, i);
         break;
         default:
            carry += (str_num[len - 1 - i] - '0') * m_power(16, i);
      }
   }

   while ( carry > 0 )  {
      dec[length] = '0' + carry%10;
      carry /= 10;
      length++;;
   }

   str_reverse(dec, length);
   dec[length] = '\0';
}

int m_power(int base, int exp)  {
   int i;
   int result = 1;
   for ( i = 0; i < exp; i++ )
      result *= base;
   return result;
}

void nCopy(char dest[], char src[], size_t start, size_t stop)  {
   size_t begin = start;
   size_t end = stop;
   for ( ; begin<end; begin++ )
      dest[begin-start] = src[begin];
}

void str_reverse(char src[], int length)  {
   int i;
   int j;
   int len = length;
   for ( i = len - 1; i > 0; i-- )  {
      for ( j = 0; j < i; j++ )  {
         char tmp = src[j];
         src[j] = src[j + 1];
         src[j + 1] = tmp;
      }
   }
}
