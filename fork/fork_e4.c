/*
    Ejemplo 4 de Fork en C // EJERCICIO TIPO CONTROL
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int num = 2;
    if (fork())
    {
        if (fork()){
            num = num + 2;
        }
        else {
            fork();
            num = num + 3;
        }
    }
    else{
        num = num + 1;
    }
    printf("%d\n", num);

    return 0;
}
