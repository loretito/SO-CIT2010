/*
    Ejemplo 2 de Fork en C // EJERCICIO TIPO CONTROL
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    if( fork() == fork()){
        printf("Thanos\n");
    }
    else{
        printf("Avengers\n");
    }


    return 0;
}



