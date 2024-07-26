/*
    Ejemplo 8 de Fork en C // EJERCICIO TIPO SOLEMNE
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    pid = fork();
    printf("Ingrese un número: ");

    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        if(pid > 0){
            pid = fork();
            printf("Hello there\n");
        }
        else {
            pid = fork();
        }
    }
}