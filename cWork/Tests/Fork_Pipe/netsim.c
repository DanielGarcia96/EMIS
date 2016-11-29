#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/* Needed this so it can scale */
#define MAX_PROC 12

int countDigits(int n);
#define DIGIT_OFFSET countDigits(MAX_PROC)
#define LENPROC   8+DIGIT_OFFSET
#define LENMSG    ((LENPROC - 1)*2)+30

/* File array functions */
int isWritten(int fd, int a[], int size);
void writeFile(int fd, int a[], int *size);

/* Writing functions */
void writeEntry(int fd, char msg[], int length);
void writeMsg(int process, int pipes[MAX_PROC][2]);

/* Reading functions */
void readMsg(int process, int fd);
void readEntry(int fd, char msg[], int length);

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

    writeMsg(procn, pipes);
    readMsg(procn, pipes[procn][0]);
    return 0;
}

void writeMsg(int process, int pipes[MAX_PROC][2])
{
    int num, i, j = 0; 
    int a[MAX_PROC-1], size = 0;
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

        //If I've already written to the selected pipe, and I haven't
        //written to enough pipes already, I have to select again
        if(isWritten(j, a, size))
        {
            i--;
            continue;
        }
        

        //load the message into the selected pipe
        char msg[LENPROC];
        sprintf(msg, "process%.*d", DIGIT_OFFSET, process);

        writeEntry(pipes[j][1], msg, LENPROC);
        close(pipes[j][1]);
        close(pipes[j][0]);

        //Put that pipe on the list of pipes written to
        writeFile(j, a, &size);
    }
}

void readMsg(int process, int fd)
{
    int i;
    char r_proc[LENPROC], msg[LENMSG];
    for(i=0; i<MAX_PROC-1; i++)
    {
        //read the process
        readEntry(fd, r_proc, LENPROC);
        
        //format the message
        sprintf(msg, "process%.*d has received a message from ", DIGIT_OFFSET, process);
        strcat(msg, r_proc);
        strcat(msg, "\n");

        //write it out
        //writeEntry(STDOUT_FILENO, msg, LENMSG);
    }

    //take care of the last pipe
    close(fd);
}


int countDigits(int n)
{
    int cnt = 0;
    while(n > 0)
    {
        cnt++;
        n/=10;
    }
    return cnt;
}

int isWritten(int fd, int a[], int size)
{
    int i;
    for(i=0; i<size; i++)
        if(a[i] == fd)
            return 1;
    return 0;
}

void writeFile(int fd, int a[], int *size) 
{
    *size += 1;
    a[*size - 1] = fd;
}

void writeEntry(int fd, char msg[], int length)
{
    if(write(fd, msg, length) <= 0)
    {
        perror("Writing error");
        exit(-1);
    }  
}

void readEntry(int fd, char msg[], int length)
{
    if(read(fd, msg, length) <= 0)
    {
        perror("Reading error");
        exit(-1);
    }
}
