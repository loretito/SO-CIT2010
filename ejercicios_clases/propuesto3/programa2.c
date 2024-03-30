/*
    Ejercicio Propuesto
    Tipo Control  
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>


int main(){ // Programa 2
    printf("%d\n", getpid());
    execv("./programa1", NULL);
    fork();
    
    printf("%d\n", getpid());

    return 0;
}