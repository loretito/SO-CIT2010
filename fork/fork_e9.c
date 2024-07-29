/*
    Ejemplo 9 de Fork en C 
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    
    pid_t me = getpid();

    pid_t pid = fork();

    if(pid == me) {
        printf("Gato\n");
    }

    for (int i = 0; i < 2; i++){
        pid_t pid = fork();

        if(getpid() == me){
            printf("Perro\n");
        }
    }
}