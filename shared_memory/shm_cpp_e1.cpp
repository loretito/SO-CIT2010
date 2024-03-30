/*
    Ejemplo 1 de Shared Memory en C++
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main()
{
    int shmid;
    key_t key = 1234;

    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1)
    {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        // proceso hijo
        char *shmaddr = (char *)shmat(shmid, NULL, 0);
        if (shmaddr == (char *)-1)
        {
            perror("shmat");
            exit(EXIT_FAILURE);
        }

        sprintf(shmaddr, "Hola! Soy el proceso hijo :3");
        if (shmdt(shmaddr) == -1)
        {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    }
    else
    {
        // proceso padre
        wait(NULL);

        char *shmaddr = (char *)shmat(shmid, NULL, 0);
        if (shmaddr == (char *)-1)
        {
            perror("shmat");
            exit(EXIT_FAILURE);
        }

        printf("Mensaje recibido (en la memoria compartida): %s\n", shmaddr);

        if (shmdt(shmaddr) == -1)
        {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }

        // Eliminar la memoria compartida
        if (shmctl(shmid, IPC_RMID, NULL) == -1)
        {
            perror("shmctl");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}