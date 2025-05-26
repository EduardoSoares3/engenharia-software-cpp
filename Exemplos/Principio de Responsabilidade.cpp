#include <iostream>
#include <string>

class Entrada {
public:
    std::string lerMensagem() {
        return "Olá, mundo!";
    }
};

class Saida {
public:
    void mostrarMensagem(const std::string& msg) {
        std::cout << msg << std::endl;
    }
};

int main() {
    Entrada entrada;
    Saida saida;
    saida.mostrarMensagem(entrada.lerMensagem());
    return 0;
}

-A classe Entrada é responsável apenas por obter dados.

-A classe Saida é responsável apenas por exibir dados.

-Cada classe tem uma única razão para mudar, seguindo o SRP.




### Princípio Aberto-Fechado (OCP - Open/Closed Principle)

Os módulos devem ser abertos para extensão, mas fechados para modificação. Devemos ser capazes de estender o comportamento de um módulo sem alterar seu código-fonte original. Isso promove flexibilidade e diminui o risco de bugs.

---

###Exemplo:

```cpp
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