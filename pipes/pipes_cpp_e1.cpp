/*
    Ejemplo 1 de Pipes ánonimos en C++
*/

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>
#include <cerrno>
#include <cstdlib>
#include <cstdio>

#define READ 0
#define WRITE 1

using namespace std;

int main(int argc, char *argv[]) {
    int fd1[2];
    pid_t pid;

    if (pipe(fd1) == -1) {
        perror("pipe");
        return -1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return -1;
    }

    if (pid == 0) {
        // Proceso hijo

        close(fd1[WRITE]);

        char buffer[100];
        int bytes_read;

        bytes_read = read(fd1[READ], buffer, sizeof(buffer));

        if (bytes_read == -1) {
            perror("Read Pipe");
            exit(-1);
        }

        // Señal de termino
        buffer[bytes_read] = '\0';

        cout << "Mensaje recibido: " << buffer << endl;

        close(fd1[READ]);
    } else {
        // Proceso padre

        close(fd1[READ]);

        const char *msg = "Hola, soy tu hijo uwu";
        ssize_t bytes_written;

        bytes_written = write(fd1[WRITE], msg, strlen(msg));

        if (bytes_written == -1) {
            perror("Write Pipe");
            exit(-1);
        }

        cout << "Mensaje enviado: " << msg << endl;

        close(fd1[WRITE]);
    }

    return 0;
}
