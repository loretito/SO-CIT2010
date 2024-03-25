/*
    Ejemplo 1 de Pipes ánonimos en C
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define READ 0  
#define WRITE 1 

int main(int argc, char *argv[])
{
    int fd1[2];
    pid_t pid;

    pipe(fd1);  

    pid = fork(); 
 
    if(pid == 0){   
        //Proceso hijo

        close(fd1[WRITE]); 

        char buffer[100];
        int bytes_read;

        bytes_read = read(fd1[READ], buffer, sizeof(buffer));

        if(bytes_read == -1){
            perror("Read Pipe");
            exit(-1);
        }

        // Señal de termino
        buffer[bytes_read] = '\0'; 

        printf("Mensaje recibido: %s\n", buffer);

        close(fd1[READ]);
    } else {
        //Proceso padre

        close(fd1[READ]); 

        char *msg = "Hola, soy tu hijo uwu";
        ssize_t bytes_written;

        bytes_written = write(fd1[WRITE], msg, strlen(msg));
        
        if(bytes_written == -1){
            perror("Write Pipe");
            exit(-1);
        }

        printf("Mensaje enviado: %s\n", msg);

        close(fd1[WRITE]);

    }

    return 0;
}