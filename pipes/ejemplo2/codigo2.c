#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    const char *fifo_path = "./my_fifo";
    int fd;
    int signal;

    fd = open(fifo_path, O_RDONLY);

    read(fd, &signal, sizeof(signal));

    if (signal == 1) {
        printf("¡Hola, uwu!\n");
    } else if (signal==2) {
        printf("¡Hola, owo!\n");
    } else {
        printf("Señal desconocida: %s\n", signal);
    }

    close(fd);

    unlink(fifo_path);

    return 0;
}
