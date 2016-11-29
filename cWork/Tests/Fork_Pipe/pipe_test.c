#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX_PROC 10
int countDigits(int n);

#define DIGIT_OFF countDigits(MAX_PROC)
#define LENPROC   8+DIGIT_OFF
#define LENMSG    ((LENPROC - 1)*2)+30

int isWritten(int fd, int a[], int size);
void writeFile(int fd, int a[], int *size);
void writeMsg(int process, int pipes[MAX_PROC][2]);
void readMsg(int process, int fd);

void printArray(int a[], int size, int process);

int main(int argc, char *argv[])
{
    pid_t pp = getpid();
    int pipes[MAX_PROC][2];
    int procn = 0;
   
    int i;
    for(i=0; i<MAX_PROC; i++)
        pipe(pipes[i]);

    for(i=0; i<MAX_PROC-1; i++)
    {
        int f = fork();
        if(f == -1)
        {
            perror("Forking error");
            return -1;
        }
        else if(f == 0)
            break;
    }

    writeMsg(process, pipes);
    readMsg(process, pipes[process][0]);

//    char string[256];
//    sprintf(string, "Process %d has exited\n", process);
//    write(STDOUT_FILENO, string, strlen(string));
    return 0;
}

void writeMsg(int process, int pipes[MAX_PROC][2])
{
    int i, j = 0, rng = RAND_MAX/10, num;
    int a[MAX_PROC-1], size = 0;
    rng *= 10;
    for(i=0; i<MAX_PROC; i++)
    {
        do {
            num = rand();
            j = num%10;
        }
        while(num >= rng || process == j);

        if(isWritten(j, a, size) && size<MAX_PROC-1)
        {
            i--;
            continue;
        }

        char msg[LENPROC];
        sprintf(msg, "process%.*d", DIGIT_OFF, process);

        write(pipes[j][1], msg, LENPROC);
        close(pipes[j][1]);
        close(pipes[j][0]);
        writeFile(j, a, &size);
    }
}

void readMsg(int process, int fd)
{
    int i;
    char r_proc[LENPROC], msg[LENMSG];
    for(i=0; i<MAX_PROC-1; i++)
    {
        read(fd, r_proc, LENPROC);
        sprintf(msg, "process%.*d has received a message from ",
                DIGIT_OFF, process);
        strcat(msg, r_proc);
        strcat(msg, "\n");
        if(write(STDOUT_FILENO, msg, LENMSG) == -1)
        {
            perror("Error writing");
            exit(-1);
        }
    }

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

void printArray(int a[], int size, int process)
{
    printf("Process %d: [ ", process);
    int i;
    for(i=0; i<size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("]\n");
}
