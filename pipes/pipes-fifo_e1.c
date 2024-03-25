/*
    Ejemplo 1 de Named Pipes (FIFO) en C
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
    pid_t pid;
    char message[] = "Hola, soy tu hijo uwu";
    char buffer[BUFSIZ];

    // Crear el named Pipe (0666 permisos) -> read 
    if(mkfifo(FIFO_NAME, 0666) == -1){
        perror("mkfifo");
        exit(-1);
    }

    if((pid = fork()) == -1){
        perror("fork");
        exit(-1);
    }

    if( pid == 0) {
        // Proceso hijo

        fd = open(FIFO_NAME, O_RDONLY); // read
        if(fd == -1){
            perror("open");
            exit(-1);
        }

        ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
        if(bytes_read == -1){
            perror("read");
            exit(-1);
        }

        printf("Mensaje recibido: %s\n", buffer);

        close(fd);
    }
    else {
        // Proceso padre

        fd = open(FIFO_NAME, O_WRONLY); // write
        if(fd == -1){
            perror("open");
            exit(-1);
        }

        ssize_t bytes_written = write(fd, message, strlen(message));
        if(bytes_written == -1){
            perror("write");
            exit(-1);
        }

        printf("Mensaje enviado: %s\n", message);

        close(fd);
    }

    //e;iminar el FIFO
    unlink(FIFO_NAME); 

    return 0;
}