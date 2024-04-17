#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int counter;
    pthread_mutex_t mutex;
    pthread_cond_t cond_var;
} Monitor;

void init_monitor(Monitor* monitor) {
    monitor->counter = 0;
    pthread_mutex_init(&(monitor->mutex), NULL);
    pthread_cond_init(&(monitor->cond_var), NULL);
}

void destroy_monitor(Monitor* monitor) {
    pthread_mutex_destroy(&(monitor->mutex));
    pthread_cond_destroy(&(monitor->cond_var));
}

void increase(Monitor* monitor) {
    pthread_mutex_lock(&(monitor->mutex));
    monitor->counter++;
    printf("El counter se incrementó a %d\n", monitor->counter);
    pthread_mutex_unlock(&(monitor->mutex));
}

void decrease(Monitor* monitor) {
    pthread_mutex_lock(&(monitor->mutex));
    monitor->counter--;
    printf("El counter se decrementó a %d\n", monitor->counter);
    pthread_mutex_unlock(&(monitor->mutex));
}

int main() {
    Monitor monitor;
    init_monitor(&monitor);

    increase(&monitor);
    decrease(&monitor);

    destroy_monitor(&monitor);

    return 0;
}
