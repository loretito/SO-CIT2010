#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define M_BOLETO_VIP 10 //M_VIP
#define N_BOLETOS_GENERALES 20 //N_GENERAL 

int asientos_VIP[M_BOLETO_VIP] = {0};
int asientos_generales = 0;

pthread_mutex_t mutex_VIP = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_general = PTHREAD_MUTEX_INITIALIZER;

void* comprar_VIP(void* arg) {
    pthread_mutex_lock(&mutex_VIP);
    for (int i = 0; i < M_BOLETO_VIP; i++) {
        if (asientos_VIP[i] == 0) {
            asientos_VIP[i] = 1;
            printf("Asiento asignado a cliente, en el asiento VIP %d\n", i);
            break;
        }
    }
    pthread_mutex_unlock(&mutex_VIP);
}

void* comprar_general(void* arg) {
    pthread_mutex_lock(&mutex_general);
    if (asientos_generales < N_BOLETOS_GENERALES) {
        asientos_generales++;
        int asiento = asientos_generales;
        printf("Asiento general comprado %d\n");
    }
    pthread_mutex_unlock(&mutex_general);
}
