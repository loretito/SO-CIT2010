#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int completos[20] = {0};
int ya_comio[12] = {0};

int todos = 0;

pthread_mutex_t mutex_completos = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER;
pthread_mutex_t todos_comen = PTHREAD_MUTEX_INITIALIZER;

void* comer(void* args , int i) {
    int completo_c = *(int*)args;

    while (ya_comio[i] && todos==0) {
        pthread_cond_wait(&cond_var, &todos_comen);
    }
    pthread_mutex_lock(&mutex_completos);
  
    ya_comio[i] = 1;
    completos[completo_c] = 0;
    pthread_mutex_unlock(&mutex_completos);
  
    //check_comieron funcion que retorna un 0 o 1 
    todos = check_comieron(ya_comio); 
  
    if (todos) {
        pthread_cond_signal(&cond_var);
    }
}