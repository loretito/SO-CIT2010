/*
    Ejemplo 1 de Conditional Variable en C 
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int lock = 0;
int value = 1;

void* function1(void*  arg){
    while(lock);
    lock = 1;
    int i;
    for(i = 0; i < 2; i++){
        value = value + 1;
    }
    lock = 0;
    return NULL;
}

void* function2(void*  arg){
    while(lock);
    lock = 1;
    int i;
    for(i = 0; i < 2; i++){
        value = value * 2;
    }
    lock = 0;
    return NULL;
}

int main(){
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, function1, NULL);
    pthread_create(&thread2, NULL, function2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("El valor final de value es: %d\n", value);

    return 0;
}