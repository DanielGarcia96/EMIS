#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

pthread_mutex_t m;

void funcA();

int main() {
    int rc;
    if((rc = pthread_mutex_init(&m, NULL))) {
        perror("Thread error");
        exit(rc);
    }

    funcA();
    return 0;
}
