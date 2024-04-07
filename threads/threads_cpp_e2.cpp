/*
    Ejemplo 2 de Threads en C++
*/

#include <iostream>
#include <thread>
#include <vector>

#define NUMBER_OF_THREADS 10

using namespace std;

void print_hello_world(int tid) {
    std::cout << "-> Hii, soy el thread " << tid << std::endl;
}

int main() {
    std::vector<std::thread> threads;
    
    for (int i = 0; i < NUMBER_OF_THREADS; i++) {
        std::cout << "Creando thread " << i << std::endl;
        threads.push_back(std::thread(print_hello_world, i));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
