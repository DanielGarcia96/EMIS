#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include "nqueens_library.h"

#define ERR_ARG 1

pthread_mutex_t m;

int main(int argc, char *argv[]) {
    int rc;
    if((rc = pthread_mutex_init(&m, NULL))) {
        fprintf(stderr, "A problem occurred when creating a mutex, exiting program.\n");
        exit(rc);
    }

    queens_thread(NULL);
    
    return 0;
}
