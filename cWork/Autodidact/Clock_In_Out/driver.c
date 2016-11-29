#include "clock_f.h"

int main(int argc, char *argv[])  {
   if(argc < 2)  {
      fprintf(stderr, "Usage: %s <in/out>\n", argv[0]);
      return 1;
   }

   FILE *fp;

   if(strcmp(argv[1], "in") == 0)  {
      fp = fopen("time_table.txt", "a+"); 
      clock_in(fp);
   }
   else if(strcmp(argv[1], "out") == 0)  {
      fp = fopen("time_table.txt", "r+"); 
      clock_out(fp);
   }
   else
      fprintf(stderr, "Invalid command:\n\tUse \"in\" or \"out\"\n");
   
   fclose(fp);
   return 0;
}
