#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])  {
   char buffer[3];
   char chr;
   scanf("%s ", buffer);
   while((chr = (char) strtol(buffer, NULL, 16)) != 0) {
      printf("%c", chr);
      scanf("%s ", buffer);
   }
   printf("\n");
   return 0;
}
