#include <iostream>

class Motor {
public:
    void ligar() {
        std::cout << "Motor ligado." << std::endl;
    }
};

class Carro {
    Motor motor;  // Composição: Carro "tem um" Motor
public:
    void ligarCarro() {
        motor.ligar();
        std::cout << "Carro funcionando." << std::endl;
    }
};

int main() {
    Carro carro;
    carro.ligarCarro();
    return 0;
}