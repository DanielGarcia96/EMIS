#include <stdio.h>
#include <string.h>

#define BUF  4096
#define STOP 1000

void big_num_add(char a[], char b[], char res[]);
int  count_digits(char n[]);
void m_copy(char dest[], char src[]);
void nSet(int start, int stop, char string[], char fill);
void reverse_print(char string[], int cnt);

int main(void)  {
   char a[BUF] = "1";
   char b[BUF] = "1";
   char c[BUF] = "0";
   int c_len = 1;
   int index = 2;

   nSet(1, BUF, a, '\0');
   nSet(1, BUF, b, '\0');
   nSet(1, BUF, c, '\0');

   while ( c_len < STOP )  {
      /*printf("a = ");
      reverse_print(a, count_digits(a));
      printf("b = ");
      reverse_print(b, count_digits(b));*/
      big_num_add(a, b, c);
      c_len = count_digits(c);
      /*printf("c = ");
      reverse_print(c, c_len);*/
      m_copy(a, b);
      m_copy(b, c);
      nSet(0, BUF, c, '\0');
      index++;
   }
   
   printf("%d\n", index);
   return 0;
}

void big_num_add(char a[], char b[], char res[])  {
   int carry = 0;
   int i;
   int len1;
   int len2;
   int start_a;
  
   if ( count_digits(a) < count_digits(b) )  {
       start_a = 1;
       len1 = count_digits(a);
       len2 = count_digits(b);
   }
   else  {
       start_a = 0;
       len1 = count_digits(b);
       len2 = count_digits(a);
   }
   

   for ( i = 0; i < len1; i++ )  {
      carry += a[i] - '0';
      carry += b[i] - '0';
      res[i] = '0' + (carry % 10);
      carry /= 10;
   }

   for ( ; i < len2; i++ )  {
      if(start_a)
         carry += b[i] - '0';
      else
         carry += a[i] - '0';
      res[i] = '0' + (carry % 10);
      carry /= 10;
   }

   while ( carry > 0 )  {
      res[i] = '0' + (carry % 10);
      carry /= 10;
      i++;
   }
}

int count_digits(char n[])  {
   int count = 0;
   while ( n[count] != '\0' )
      count++;

   return count;
}

void nSet(int start, int stop, char string[], char fill)  {
   int begin = start;
   int end = stop;
   int i;
   for ( i = begin; i < end; i++ )
      string[i] = fill;
}

void reverse_print(char string[], int cnt)  {
   int i;
   for ( i = cnt-1; i >= 0; i-- )
      printf("%c", string[i]);
   printf("\n");
}

void m_copy(char dest[], char src[])  {
   int count = 0;
   while ( src[count] != '\0' )  {
      dest[count] = src[count];
      count++;
   }
}

