#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

struct cmd
{
    int redirect_in;     /* Any stdin redirection?         */
    int redirect_out;    /* Any stdout redirection?        */
    int redirect_append; /* Append stdout redirection?     */
    int background;      /* Put process in background?     */
    int piping;          /* Pipe prog1 into prog2?         */
    char *infile;        /* Name of stdin redirect file    */
    char *outfile;       /* Name of stdout redirect file   */
    char *argv1[10];     /* First program to execute       */
    char *argv2[10];     /* Second program in pipe         */
};

void printCmd(struct cmd *com);
int cmdscan(char *cmdbuf, struct cmd *com);

int main(void)
{
    //Allocate any necessary resources
    char buf[1024];
    int cmd_count = 0;
    struct cmd command;

    //Start the prompt for the shell
    printf("$");
    fgets(buf, 1024, stdin);

    //End the loop if an exit is encountered
    while(strcmp(buf, "exit") != 0){
        //Fill out command struct
        //if an error is encountered, repeat
        if(cmdscan(buf, &command)){
            printf("Illegal Format:\n");
            printf("$");
            fgets(buf, 1024, stdin);
            buf[strlen(buf)-1] = '\0';
            continue;
        }

        //Fork off the command 
        int status;
        switch(fork()){
            case -1:
                perror("Piping error");
                exit(-1);
            break;
            case 0:
            break;
            default: 
                if(!command.background || cmd_count >= 10)
                {
                    wait(&status);
                    printf("$");
                }
                else
                    printf("$\n");
                fgets(buf, 1024, stdin);
                buf[strlen(buf)-1] = '\0';
                continue;
        }

        int p[2];
        if(pipe(p) == -1){
            perror("Piping error");
            exit(-1);
        }

        pid_t f = 1;
        int fdIn, fdOut;
        if(command.piping)
            f = fork();
        else
        {
            close(p[0]);
            close(p[1]);
        }

        switch(f){
            case -1:
                perror("Forking error");
                exit(-1);
            break;
            case 1:
                close(p[1]);
                close(p[0]);
                if(command.redirect_in) {
                    fdIn = open(command.infile, O_RDONLY);
                    dup2(fdIn, STDIN_FILENO);
                    close(fdIn);
                }

                if(command.redirect_out) {
                    if(command.redirect_append) {
                        fdOut = open(command.outfile, O_WRONLY | O_APPEND | O_CREAT, 
                                     S_IROTH | S_IRGRP | S_IWGRP | S_IRUSR | S_IWUSR);
                        dup2(fdOut, STDOUT_FILENO);
                        close(fdOut);
                    }
                    else {
                        fdOut = open(command.outfile, O_WRONLY | O_CREAT,
                                     S_IROTH | S_IRGRP | S_IWGRP | S_IRUSR | S_IWUSR);
                        dup2(fdOut, STDOUT_FILENO);
                        close(fdOut);
                    }

                }
                
                if(execvp(command.argv1[0], command.argv1) == -1) {
                    perror("Error executing program1");
                    exit(-1);
                }
            break;
            case 0:
                close(p[0]);
                if(command.redirect_in) {
                    fdIn = open(command.infile, O_RDONLY);
                    dup2(fdIn, STDIN_FILENO);
                    close(fdIn);
                }

                if(command.redirect_out) {
                    if(command.redirect_append) {
                        fdOut = open(command.outfile, O_WRONLY | O_APPEND | O_CREAT, 
                                     S_IROTH | S_IRGRP | S_IWGRP | S_IRUSR | S_IWUSR);
                        dup2(fdOut, STDOUT_FILENO);
                        close(fdOut);
                    }
                    else {
                        fdOut = open(command.outfile, O_WRONLY | O_CREAT,
                                     S_IROTH | S_IRGRP | S_IWGRP | S_IRUSR | S_IWUSR);
                        dup2(fdOut, STDOUT_FILENO);
                        close(fdOut);
                    }                
                }
                else {
                    if(command.piping) {
                        dup2(p[1], STDOUT_FILENO);
                        close(p[1]);
                    }
                }

                if(execvp(command.argv1[0], command.argv1) == -1) {
                    perror("Error executing program1");
                    exit(-1);
                }
            default:
                waitpid(f, &status, 0);
                close(p[1]);
                if(command.piping) {
                        dup2(p[0], STDIN_FILENO);
                        close(p[0]);
                }
                else if(command.redirect_in) {
                    fdIn = open(command.infile, O_RDONLY);
                    dup2(fdIn, STDIN_FILENO);
                    close(fdIn);
                }

                if(command.redirect_out) {
                    if(command.redirect_append) {
                        fdOut = open(command.outfile, O_WRONLY | O_APPEND | O_CREAT, 
                                     S_IROTH | S_IRGRP | S_IWGRP | S_IRUSR | S_IWUSR);
                        dup2(fdOut, STDOUT_FILENO);
                        close(fdOut);
                    }
                    else {
                        fdOut = open(command.outfile, O_WRONLY | O_CREAT,
                                     S_IROTH | S_IRGRP | S_IWGRP | S_IRUSR | S_IWUSR);
                        dup2(fdOut, STDOUT_FILENO);
                        close(fdOut);
                    }
                }
                
                if(execvp(command.argv2[0], command.argv2) == -1) {
                    perror("Error executing program2");
                    exit(-1);
                }
        }

    }
    return 0;
}

void printCmd(struct cmd *com)
{
    int i = 0;
    printf("prog1 = ");
    printf("%s\n",com->argv1[i++]);
    while( com->argv1[i] != NULL )
        printf("        %s\n",com->argv1[i++]);
    printf("redirect_in = %d\nredirect_out = %d\nredirect_append = %d\nbackground = %d\npiping = %d\n",
         com->redirect_in, com->redirect_out, com->redirect_append, 
         com->background, com->piping);
    if ( com->redirect_in )
      printf("infile = %s\n", com->infile);
    if ( com->redirect_out )
      printf("outfile = %s\n", com->outfile);
    if ( com->piping ) {
      i = 0;
      printf("prog2 = ");
      printf("%s\n",com->argv2[i++]);
      while( com->argv2[i] != NULL )
        printf("        %s\n",com->argv2[i++]);
    }
}
