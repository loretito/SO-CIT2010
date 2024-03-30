/*
    Ejemplo 1 de Fork en C++
*/

#include <iostream> 
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main() {
    pid_t pid;
    
    pid = fork();

    if (pid == 0) {
        cout << "Soy el proceso hijo, pid: " << getpid() << endl;
    } else {
        cout << "Soy el proceso padre, pid: " << getpid() << endl;
    }

}