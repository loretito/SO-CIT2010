#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define M_BOLETO_VIP 10 //M_VIP
#define N_BOLETOS_GENERALES 20 //N_GENERAL 

int asientos_VIP[M_BOLETO_VIP] = {0};
int asientos_generales = 0;

pthread_mutex_t mutex_VIP = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_general = PTHREAD_MUTEX_INITIALIZER;

int funcion_actual = 0;
int vip_lleno = 0;
int general_lleno = 0;

void reiniciar_ventas() {
    pthread_mutex_lock(&mutex_general);
    pthread_mutex_lock(&mutex_VIP);
    
    guardar_en_BD();
    
    for (int i = 0; i < M_BOLETO_VIP; i++) {
        asientos_VIP[i] = 0;
    }
    asientos_generales = 0;
    
    pthread_mutex_unlock(&mutex_VIP);
    pthread_mutex_unlock(&mutex_general);
}

void* comprar_galeria(void* arg) {
    pthread_mutex_lock(&mutex_VIP);
    int encontrado = 0;
    for (int i = 0; i < M_BOLETO_VIP; i++) {
        if (asientos_VIP[i] == 0) {
            asientos_VIP[i] = 1;
            printf("Asiento asignado a cliente, en el asiento VIP %d\n", i);
            encontrado = 1;
            break;
        }
    }
    if ((!vip_lleno) && (!encontrado)) {
        vip_lleno = 1;
    }
    pthread_mutex_unlock(&mutex_VIP);
    
    if (general_lleno && vip_lleno) {
        reiniciar_ventas();
    }
}

void* comprar_general(void* arg) {
    pthread_mutex_lock(&mutex_general);
    if (asientos_generales < N_BOLETOS_GENERALES) {
        asientos_generales++;
        int asiento = asientos_generales;
        printf("Lugar asignado a cliente, asiento general %d\n", asiento);
    } else {
        general_lleno = 1;
    }
    pthread_mutex_unlock(&mutex_general);
    
    if (general_lleno && vip_lleno) {
        reiniciar_ventas();
    }
}
