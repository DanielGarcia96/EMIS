#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include "nqueens_library.h"

extern pthread_mutex_t m;

void *queens_thread(void *infopointer) {
    pthread_mutex_lock(&m);
    printf("%d %d\n", 1, 2);
    pthread_mutex_unlock(&m);
    return NULL;
}
