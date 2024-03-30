/*
    Ejemplo 5 de Fork en C, creacion de procesos hijos directos del proceso padre
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid = getpid();
    pid_t child_pid;
    for (int i = 0; i < 5; i++){
        if(pid == getpid()){
            printf("Soy el proceso padre con PID %d\n", getpid());
            child_pid = fork(); 

            if(child_pid == 0){ // Proceso hijo sale del bucle
                break;
            }
        }
    }
    

    return 0;
}
