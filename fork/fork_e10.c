/*
    Ejemplo 10 de Fork en C 
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
    int status;

    for (int i = 0; i < 2; i++)
    {
        pid = fork();

        if (pid == 0)
        {
            printf("Spiderman\n");
            for (int j = 0; j < 2; j++)
            {
                pid_t nested_pid = fork();
                if (nested_pid == 0)
                {
                    printf("Venom\n");
                    exit(0);
                }
                else if (nested_pid > 0)
                {
                    wait(&status);
                }
            }
            exit(0);
        }
        else if (pid > 0)
        {
            wait(&status);
        }
    }

    return 0;
}
