#include "clock_f.h"

int clock_in(FILE *fp)  {
   char *buffer;
   struct tm *loctime;
   size_t offset;
   time_t start;

   start = time(NULL);
   loctime = localtime(&start);
   buffer = asctime(loctime);
   offset = sizeof(time_t);

   fprintf(fp, "Clocked in: ");

   if (fwrite(buffer, 1, strlen(buffer), fp) != strlen(buffer))  {
      perror("Error writing to file");
      fclose(fp);
      return -1;
   }

   if (fwrite(&start, 1, offset, fp) != offset)  {
      perror("Error writing to file");
      fclose(fp);
      return -1;
   }

   if (fseek(fp, -offset, SEEK_CUR) != 0)  {
      perror("Error seeking within file");
      fclose(fp);
      return -1;
   }

   return 0;
}

int clock_out(FILE *fp)  {
   char  *buffer;
   time_t end;
   struct tm *endtime;
   size_t offset;
   time_t start;
   double seconds_worked = 0;

   end = time(NULL);
   endtime = localtime(&end);
   buffer = asctime(endtime);
   offset = strlen(buffer);

   if(fseek(fp, -sizeof(time_t), SEEK_END) != 0)  {
      perror("Error seeking within file");
      printf("%d\n", __LINE__);
      fclose(fp);
      return -1;
   }

   if(fread(&start, 1, sizeof(time_t), fp) != sizeof(time_t))  {
      perror("Error reading file");
      fclose(fp);
      return -1;
   }

   if(fseek(fp, -sizeof(time_t), SEEK_CUR) != 0)  {
      perror("Error seeking within file");
      printf("%d\n", __LINE__);
      fclose(fp);
      return -1;
   }

   seconds_worked = difftime(end, start);

   fprintf(fp, "Clocked out: ");

   if (fwrite(buffer, 1, offset, fp) != offset)  {
      perror("Error writing to file");
      fclose(fp);
      return -1;
   }

   fprintf(fp, "Worked %d Hours, %d Minutes, and %d Seconds\n\n", 
          ((int) (seconds_worked/60)/60), 
          (int) (seconds_worked/60),
          (int) seconds_worked % 60);

   return 0;
}
