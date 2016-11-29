#include <stdio.h>
#include <pthread.h>

extern pthread_mutex_t m;

void funcA() {
    pthread_mutex_lock(&m);
    pthread_mutex_unlock(&m);
}
