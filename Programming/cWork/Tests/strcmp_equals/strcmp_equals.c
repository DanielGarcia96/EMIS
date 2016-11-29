#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])  {
   char *input = "-input";
   char *ins = input;
   if(argc < 2)
      exit(1);
   if(argv[1] == input)
      printf("input compares with argv\n");
   if(argv[1] == ins)
      printf("ins compares with argv\n");
   if(strcmp(argv[1], input) == 0)
      printf("input string compares with argv\n");
   return 0;
}
