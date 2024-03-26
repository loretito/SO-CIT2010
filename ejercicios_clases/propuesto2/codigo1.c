/*
    Ejemplo Vistó en Clase
    Control 1, 2023-02 
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int main(){ 
    pid_t a = getpid();
    pid_t b = fork();

    printf("It's a me, ");
    if( b > 0 ){
        sleep(10);
        printf(" dean");
    }
    else {
        kill(a, SIGKILL);
        printf("Luigi\n");
        sleep(5);
        exit(0);
    }

    return 0;
}