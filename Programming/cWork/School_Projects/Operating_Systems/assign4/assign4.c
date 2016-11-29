#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "nqueens_library.h"

#define ERR_ARG 1

pthread_mutex_t m;

int main(int argc, char *argv[]) {
    int i, j, n;
    thread_info_t *t = (thread_info_t *) malloc(sizeof(thread_info_t));
    t->out_flag = 0;

    if(argc < 2) {
        fprintf(stderr, "Please enter a number of queens\n");
        exit(ERR_ARG);
    }

    n = atoi(argv[1]);

    for(i=0; i < n; i++) {
        t->n = i;
        for(j=0; j < i; j++) {
            t->first = j;
            queens_thread(t);
        }
    }
    
    free(t);
    return 0;
}
