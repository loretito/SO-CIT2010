#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int completos[20] = {0};
int ya_comio[12] = {0};

pthread_mutex_t mutex_completo = PTHREAD_MUTEX_INITIALIZER;


void* comer(void* args, int i) {
    int completo_c = *(int*)args;

    pthread_mutex_lock(&mutex_completo);
  
    ya_comio[i] = 1;
    completos[*(int*)completo_c] = 0;
  
    pthread_mutex_unlock(&mutex_completo);
}