#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include "nqueens_library.h"

#define ERR_ARG 1
#define ERR_THREAD 2

void *thread_helper(void *args) {
    int j;
    thread_info_t *t = (thread_info_t *) args;
    int n = t->n;
    for(j=0; j < n; j++) {
        t->first = j;
        char buffer[256];
        sprintf(buffer, "n == %d\nt->n == %d\nt->first == %d\nt->out_flag == %d\n", 
                         n, t->n, t->first, t->out_flag);
        write(STDIN_FILENO, buffer, strlen(buffer));
        queens_thread(t);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    int i, j, n;
    thread_info_t *t = (thread_info_t *) malloc(sizeof(thread_info_t));
    t->out_flag = 0;

    if(argc < 2) {
        fprintf(stderr, "Please enter a number of queens\n");
        exit(ERR_ARG);
    }

    n = atoi(argv[1]);

    pthread_t threads[n];
    thread_info_t info[n];
    for(i=0; i < n; i++) {
        int k;
        for(k = 0; k < i; k++) {
            info[k].n = i;
            info[k].out_flag = 0;
        }

        for(j=0; j < i; j++) {
            info[j].first = j;
            //printf("starting thread %d:%d\n", info[j].n, info[j].first);
            int rc = pthread_create(&threads[j], NULL, &queens_thread, (void *) &(info[j]));
            if(rc) {
                fprintf(stderr, "A problem occurred when creating a thread, exiting program.\n");
                exit(ERR_THREAD);
            }
        }

        for(j=0; j < i; j++) {
            int rc = pthread_join(threads[j], NULL);
            if(rc) {
                fprintf(stderr, "A problem occurred when joining a thread, exiting program.\n");
                exit(ERR_THREAD);
            }
        }
    }
    
    free(t);
    return 0;
}
