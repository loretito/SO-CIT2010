/*
    Ejemplo 1 de Wait en C
    Consejo: Wait puede servir para sincronizar procesos
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid;

    pid = fork();

    if(pid == 0){
        sleep(2);
        printf("Soy el proceso hijo con PID %d\n", getpid());
    }
    else{
        wait(NULL); // Espera a que el proceso hijo termine
        printf("Soy el proceso padre con PID %d\n", getpid());
    }

    return 0;
}
