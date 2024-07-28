/*
    Ejemplo 2 de Mutex en C 
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

int shared = 0;
pthread_mutex_t mutex;

void* function(void* thread_id){
    int tid = *((int*)thread_id);
    pthread_mutex_lock(&mutex);
    shared++;
    printf("El Thread %d incrementó el valor de shared a %d\n", tid, shared);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);

    int thread_ids[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++){
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, function, (void*)&thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}