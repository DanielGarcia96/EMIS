#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ERR_ARG 1
#define ERR_FRK 2
#define ERR_WR  3

struct linked_list {
    int id;
    struct linked_list *next;
};

typedef struct linked_list *list;

void freeList(list mList);
void addNode(list l, int t_id);
void printList(list mList, int process);
void writeEntry(int fd, char msg[], int length);

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        fprintf(stderr, "Usage: %s <number of processes>\n", argv[0]);
        exit(ERR_ARG);
    }

    list mList = (struct linked_list *) malloc(sizeof(struct linked_list));
    int total_proc = atoi(argv[1]), procn = 0, i;
    for(i=1; i<total_proc; i++)
    {
        int f = fork();
        if(f == -1)
        {
            perror("Forking error");
            exit(ERR_FRK);
        }
        else if(f == 0)
        {
            procn = i;
            addNode(mList, i);
            break;
        }
        addNode(mList, i);
    }
   
    printList(mList, procn);
    freeList(mList);
    return 0;
}

void addNode(list mList, int t_id)
{
    list start = mList;
    while(mList->next != NULL)
        mList = mList->next;
    
    mList->next = (list) malloc(sizeof(struct linked_list));
    mList = mList->next;
    mList->id = t_id;
    mList = start;
}


void printList(list mList, int process)
{
    char msg[4096];
    list start = mList;

    sprintf(msg, "Process %d:\n", process);
    while(mList != NULL)
    {
        char hold[10];
        sprintf(hold, "%d\n", mList->id);
        strcat(msg, hold);
        mList = mList->next;
    }
    writeEntry(STDOUT_FILENO, msg, strlen(msg));
    mList = start;
}

void freeList(list mList)
{
    while(mList != NULL)
    {
        list tmp = mList;
        mList = mList->next;
        free(tmp);
    }
}

void writeEntry(int fd, char msg[], int length)
{
    if(write(fd, msg, length) <= 0)
    {
        perror("Writing error");
        exit(ERR_WR);
    }
}
