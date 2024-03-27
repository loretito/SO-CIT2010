/*
    Ejemplo Visto en Clase
    Control 1, 2023-02 
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>


int counter = 0; //variable global
int main(){ //codigo2
    pid_t t;
    t = fork();
    if( t > 0 ){
        counter = counter * 2;
    }
    else {
        counter = counter -1;
    }
    printf("%d\n", counter);

    return 0;
}