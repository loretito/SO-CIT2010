/*
    Ejemplo 2 de Threads en C2
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUMBER_OF_THREADS 10
void *print_hello_world(void *tid)
{
    printf("-> Hii, soy el thread %ld\n", (long)tid);
    pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
    /* El programa crea 10 threads*/
    pthread_t threads[NUMBER_OF_THREADS];
    int status;
    long i;
    for (i = 0; i < NUMBER_OF_THREADS; i++)
    {
        printf("Creando thread %ld\n", i);

        status = pthread_create(&threads[i], NULL, print_hello_world, (void *)i);
        if (status != 0)
        {
            printf("Oops. pthread_create retorno el codigo de error %d\n", status);
            exit(-1);
        }
    }

    sleep(1);
    exit(0);
}
