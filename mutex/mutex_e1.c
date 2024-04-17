#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int counter = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* add_counter(void* arg) {
    pthread_mutex_lock(&mutex);

    counter++;

    printf("Thread %ld incrementó el counter a %d\n", pthread_self(), counter);

    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, add_counter, NULL);
    pthread_create(&thread2, NULL, add_counter, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("El valor final del counter es: %d\n", counter);

    return 0;
}
