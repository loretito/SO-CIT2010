/*
    Ejemplo 10 de Fork en C // Código X
    gcc codigoy.c -o Y
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() // Proceso Y
{
    pid_t t, u;
    t = getpid();
    u = fork();

    printf("t: %d\n", t);
    printf("u: %d\n", u);

    return 0;
}