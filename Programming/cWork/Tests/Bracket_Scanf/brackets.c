#include <stdio.h>

#define BUF 256

int main(int argc, char *argv[])  {
   char buffer[BUF];
   char new_buf[BUF];

   printf("Enter something and this will this ");
   printf("will print out whatever comes before a comma:");
   fgets(buffer, BUF, stdin);
   sscanf(buffer, "%[^,]", new_buf);
   printf("Modified string: %s\n", new_buf);

   return 0;
}
