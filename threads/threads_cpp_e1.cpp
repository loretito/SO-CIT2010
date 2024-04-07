/*
    Ejemplo 1 de Threads en C
*/


#include <iostream>
#include <thread>

void print_message(const std::string& message) {
    std::cout << message << std::endl;
}

int main() {
    std::thread thread1(print_message, "Hola, soy el thread 1");
    std::thread thread2(print_message, "Hola, soy el thread 2");

    thread1.join();
    thread2.join();

    return 0;
}
