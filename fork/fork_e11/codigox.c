/*
    Ejemplo 10 de Fork en C // Código X
    gcc codigox.c -o X
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() // Proceso X
{
    pid_t r, s;
    r = fork();
    s = getpid();

    printf("s: %d\n", s);
    printf("r: %d\n", r);

    if (r == 0) {
        printf("SECICO\n");
        execlp("./Y", "", NULL);
        printf("Guide\n");
    } else {
        printf("Rodi\n");
    }

    return 0;
}