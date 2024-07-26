/*
    Ejemplo 6 de Fork en C // EJERCICIO TIPO CONTROL
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int num = 1; // Variable global

int main()
{
    pid_t pid = fork();

    if (pid == -1)
    {
        return 1;
    }
    else if (pid > 0)
    {
        num = num + 1;
    }
    else
    {
        pid_t pid2 = fork();

        if (pid2 == -1)
        {
            return 1;
        }
        else if (pid2 > 0)
        {
            num = num + 2;
        }
        else
        {
            num = num - 1;
        }
    }

    printf("%d\n", num);
}