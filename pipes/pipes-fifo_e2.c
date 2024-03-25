/*
    Ejemplo 2 de Named Pipes (FIFO) en C
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define FIFO_NAME "namedfifo"

int main(int argc, char *argv[])
{
    int fd;
    int flag;
    pid_t pid;

    if (mkfifo(FIFO_NAME, 0666) == -1)
    {
        perror("mkfifo");
        exit(-1);
    }

    if ((pid = fork()) == -1)
    {
        perror("fork");
        exit(-1);
    }

    if (pid == 0)
    {
        // Proceso hijo

        fd = open(FIFO_NAME, O_RDONLY);
        if (fd == -1)
        {
            perror("open");
            exit(-1);
        }

        ssize_t bytes_read = read(fd, &flag, sizeof(flag));
        if (bytes_read == -1)
        {
            perror("read");
            exit(-1);
        }

        if (flag == 1)
        {
            printf("La flag es 1, entonces hare esto...\n");
        }
        else if (flag == 2)
        {
            printf("La flag es 2, entonces hare esto...\n");
        }
        else
        {
            printf("La flag es X, entonces hare esto...\n");
        }

        close(fd);
    }
    else
    {
        // Proceso padre

        fd = open(FIFO_NAME, O_WRONLY);
        if (fd == -1)
        {
            perror("open");
            exit(-1);
        }

        int flag = 2;
        ssize_t bytes_written;

        bytes_written = write(fd, &flag, sizeof(flag));

        if (bytes_written == -1)
        {
            perror("write");
            exit(-1);
        }

        close(fd);
    }

    unlink(FIFO_NAME);

    return 0;
}