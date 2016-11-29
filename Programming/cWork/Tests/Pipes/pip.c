#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define BUF 256
#define ERR_PIP 1
#define ERR_RAD 2
#define ERR_WRT 3

int main(int argc, char *argv[]) {
   int pip[2];
   if( pipe(pip) != 0 )
   {
      fprintf(stderr, "Error in creating pipe\n");
      return ERR_PIP;
   }

   int my_pid;
   int i;
   for(i = 0; i < 2; i++)
      if((my_pid = fork()) != 0 && my_pid == 0)
         break;

   char msg[BUF];
   sprintf(msg, "hello from %d\n", my_pid);
   int msg_len = strlen(msg);

   if(write(pip[1], msg, msg_len) < 1) {
      fprintf(stderr, "Error in writing to pipe\n");
      return ERR_WRT;
   }
   close(pip[1]);
   if(read(pip[0], msg, msg_len) < 1) {
      fprintf(stderr, "Error in reading from pipe\n");
      return ERR_RAD;
   }
   if(write(STDOUT_FILENO, msg, msg_len) < 1) {
      fprintf(stderr, "Error in writing to pipe\n");
      return ERR_WRT;
   }
   if(my_pid != 0) {
      int cstatus = 0;
      int *status = &cstatus;
      wait(status);
   }
   close(pip[0]);
   return 0;
}


