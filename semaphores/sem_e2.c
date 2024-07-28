/*
    Ejemplo 2 de Semaphores en C 
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdint.h>

sem_t sem;

void* thread_function(void* arg) {
    sem_wait(&sem);
    printf("Hola desde soy el Thread %d\n", (intptr_t)arg);
    sem_post(&sem);
    pthread_exit(NULL);
}

int main(){
    pthread_t thread1, thread2;
    sem_init(&sem, 0, 1);

    pthread_create(&thread1, NULL, thread_function, (void*)1);

    pthread_create(&thread2, NULL, thread_function, (void*)2);

    sem_wait(&sem);
    printf("Hola desde el main\n");
    sem_post(&sem);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    sem_destroy(&sem);

    return 0;
}