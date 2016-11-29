#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

intfunct1(int n);
intfunct2(char *prog1, char *prog2);
intfunct3(char *prog1, char *pargv[], char flag);
intfunct4(char *prog1, char *pargv[], int *fdread, int *fdwrite);
intfunct5(int n);

intmain(int argc, char **argv)
{
   if(argc < 2)
   {
       fprintf(stderr, "Usage:%s <program#>\n", argv[0]);
           return -1;
   }
   
   int n = 0, flag;
   char buffer[256], prog1[256], prog2[256];
   char **pargv = (char **) malloc(12*64*sizeof(char *));

   switch(atoi(argv[1]))
   {
       case 1:
           printf("Enter a number of children to spawn: ");
           fgets(buffer, 10, stdin);
           sscanf(buffer, "%d", &n);
           funct1(n);
       break;
       case 2:
	   printf("Enter the name of a zero argument executable: ");
           fgets(prog1, 256, stdin);
           prog1[strlen(prog1) - 1] = '\0';

	   printf("Enter another one: ");
           fgets(prog2, 256, stdin);
           prog2[strlen(prog2) - 1] = '\0';

           funct2(prog1, prog2);
       break;
       case 3:
           printf("Enter a program with args separated by spaces: ");
           fgets(buffer, 256, stdin);
           buffer[strlen(buffer) - 1] = '\0';
           pargv[n] = strtok(buffer, " ");
           while(pargv[n] != NULL)
           {
               n++;
               pargv[n] = strtok(NULL, " ");
           }

           flag = funct3(pargv[0], pargv, 'w');
           wait(&n);
           printf("Returned flag: %d\n", flag);
           close(flag);
       break;
       case 4:
           
       break;
       case 5:
       break;
       default:
           fprintf(stderr, "Enter a valid program number:\n\t1, 2, 3, 4, 5\n");
           free(pargv);
           return -1;
   }
   free(pargv);
   return 0;
}
