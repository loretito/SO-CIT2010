/*
    Ejemplo 3 de Fork en C // EJERCICIO TIPO CONTROL
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    pid_t pid;
    pid = fork();

    for(int i = 0; i < 3; i++){
        if(pid > 0){
            printf("Holi\n");
        }
        else{
            pid = fork();
        }
    }
}



