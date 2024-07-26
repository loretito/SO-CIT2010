/*
    Ejemplo 3 de Threads en C utilizando mutex

    Compilar: gcc threads_e3.c -o name -lpthread 
    Ejecutar: ./name <n_ciclos>
    ! -> lpthread asegura que el programa utilice la libreria de threads correctamente
*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int max;
volatile int counter = 0; 

pthread_mutex_t lock; // Mutex 

void *mythread(void *arg) {
    char *letter = arg;
    printf("%s: inicio\n", letter);
    for (int i = 0; i < max; i++) {
        pthread_mutex_lock(&lock); // Bloquea el mutex antes de acceder a la variable compartida
        counter = counter + 1;
        pthread_mutex_unlock(&lock); // Desbloquea el mutex después de modificar la variable compartida
    }
    printf("%s: terminado\n", letter);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "uso: ./pthreads2 <n_ciclos>\n");
        exit(1);
    }
    max = atoi(argv[1]);
    pthread_t p1, p2;
    pthread_mutex_init(&lock, NULL); 

    printf("Inicio [contador = %d]\n", counter);

    pthread_create(&p1, NULL, mythread, "A");
    pthread_create(&p2, NULL, mythread, "B");
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_mutex_destroy(&lock); 

    printf("Terminado\n [contador: %d]\n [esperado: %d]\n", counter, max * 2);
    return 0;
}
