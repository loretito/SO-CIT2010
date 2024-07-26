/*
    Ejemplo 7 de Fork en C // EJERCICIO TIPO CONTROL
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    pid_t t = fork();
    int i = 1;

    if (t > 0) {
        i = 6;
        sleep(2);
    } else {
        if (i == 5) {
            exit(1);
        }
        
        if (i > 5) {
            exit(2);
        } else {
            exit(3);
        }
    }

    int exit_status;

    if (i == 5) {
        exit_status = 1;
    } else if (i > 5) {
        exit_status = 2;
    } else {
        exit_status = 3;
    }

    if (exit_status == 1) {
        printf("Red\n");
    } else if (exit_status == 2) {
        printf("Dead\n");
    } else {
        printf("Redemption\n");
    }
}