/*
    Ejemplo 3 de Threads en C++
    Compilar: g++ threads_cpp_e3.cpp -o name
    Ejecutar: ./name <n_ciclos>
*/


#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

int max;
volatile int counter = 0;
std::mutex mtx; // Mutex para sincronización

void mythread(char letter) {
    std::cout << letter << ": inicio" << std::endl;
    for (int i = 0; i < max; i++) {
        mtx.lock(); // Bloquea el mutex antes de acceder a la variable compartida
        counter = counter + 1;
        mtx.unlock(); // Desbloquea el mutex después de modificar la variable compartida
    }
    std::cout << letter << ": terminado" << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "uso: ./pthreads2 <n_ciclos>" << std::endl;
        exit(1);
    }
    max = std::stoi(argv[1]);
    std::vector<std::thread> threads;

    std::cout << "Inicio [contador = " << counter << "]" << std::endl;

    threads.emplace_back(mythread, 'A');
    threads.emplace_back(mythread, 'B');

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Terminado [contador: " << counter << "] [esperado: " << max * 2 << "]" << std::endl;
    return 0;
}
