#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/* Needed this so it can scale */
#define MAX_PROC  10

#define LENPROC   8
#define PROCBUF   32
#define LENMSG    (PROCBUF*2)+25
#define PIPEBUF   256*(MAX_PROC)

/* Writing functions */
void writeEntry(int fd, char msg[], int length);
void writeMsg(int process, int pipes[MAX_PROC][2]);

/* Reading functions */
void readMsg(int process, int fd);
int readEntry(int fd, char msg[], int length);

int main(int argc, char *argv[])
{
    int pipes[MAX_PROC][2];
    int procn = 0;
   
    int i;
    for(i=0; i<MAX_PROC; i++)
    {
        if(pipe(pipes[i]) == -1)
        {
            perror("Piping error");
            exit(-1);
        }
    }

    for(i=1; i<MAX_PROC; i++)
    {
        int f = fork();
        if(f == -1)
        {
            perror("Forking error");
            return -1;
        }
        else if(f == 0)
        {
            procn = i;
            break;
        }
    }

    //close all unnecessary pipes
    close(pipes[procn][1]);
    for(i=0; i<MAX_PROC; i++)
        if(i != procn)
            close(pipes[i][0]);

    writeMsg(procn, pipes);
    readMsg(procn, pipes[procn][0]);
    return 0;
}

void writeMsg(int process, int pipes[MAX_PROC][2])
{
    int num, i, j = 0; 
    int rng = RAND_MAX/MAX_PROC;
    rng *= MAX_PROC;
    for(i=0; i<MAX_PROC-1; i++)
    {
        //Select a random pipe
        do {
            num = rand();
            j = num%MAX_PROC;
        }
        while(num >= rng || process == j);

        //load the message into the selected pipe
        char msg[PROCBUF];
        sprintf(msg, "process%d", process);
        writeEntry(pipes[j][1], msg, strlen(msg));
    }
    
    //close all write pipes once I've
    //written to them
    for(i=0; i<MAX_PROC; i++)
        if(i != process)
            close(pipes[i][1]);
}

void readMsg(int process, int fd)
{
    int index = 0;
    char msg[LENMSG], pipeBuffer[PIPEBUF] = "", 
         rproc[PROCBUF] = "";

    readEntry(fd, pipeBuffer, PIPEBUF);
    while(index < strlen(pipeBuffer))
    {
        int i;
    
        //read the string "process" in
        for(i = index; i<(index+(LENPROC-1)); i++)
            rproc[i-index] = pipeBuffer[i];

        int num = i-index;
        index += LENPROC-1;
    
        //get the process number
        while(isdigit(pipeBuffer[index]))
        {
            rproc[num] = pipeBuffer[index]; 
            index++;
            num++;
        }
    
        //format the message 
        sprintf(msg, "process%d has received a message from %s\n", process, rproc);
    
        //write it out
        writeEntry(STDOUT_FILENO, msg, strlen(msg));
   
        //empty process buffer
        memset(rproc, 0, sizeof(rproc));
    }

    //take care of the last pipe
    close(fd);
}

void writeEntry(int fd, char msg[], int length)
{
    if(write(fd, msg, length) <= 0)
    {
        perror("Writing error");
        exit(-1);
    }  
}

int readEntry(int fd, char msg[], int length)
{
    int nbytes;
    if((nbytes = read(fd, msg, length)) == -1)
    {
        perror("Reading error");
        exit(-1);
    }
    return nbytes;
}
