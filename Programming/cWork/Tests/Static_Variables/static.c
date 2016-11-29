#include <stdio.h>

int increment();

int main(int argc, char *argv[])  {
   printf("%d\n", increment());
   printf("%d\n", increment());
   printf("%d\n", increment());
   return 0;
}

int increment()  {
   static int acul = 0;
   acul++;
   return acul;
}
