/*
    Ejemplo 1 de Fork en C 
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    pid_t me;

    // retorna al padre el PID del proceso hijo y al hijo el valor 0
    me = fork();

    printf("I am %d\n", me);

    return 0;
}