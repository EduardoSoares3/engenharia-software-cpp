#include <iostream>
#include <vector>
#include <memory>

class Forma {
public:
    virtual double area() const = 0;
    virtual ~Forma() = default;
};

class Retangulo : public Forma {
    double largura, altura;
public:
    Retangulo(double l, double a) : largura(l), altura(a) {}
    double area() const override {
        return largura * altura;
    }
};

class Circulo : public Forma {
    double raio;
public:
    Circulo(double r) : raio(r) {}
    double area() const override {
        return 3.14 * raio * raio;
    }
};

int main() {
    std::vector<std::shared_ptr<Forma>> formas = {
        std::make_shared<Retangulo>(4, 5),
        std::make_shared<Circulo>(2)
    };

    for (auto& f : formas) {
        std::cout << "Área: " << f->area() << std::endl;
    }
    return 0;
}