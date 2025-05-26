P# Princípios de Design de Software

---

## Princípio da Responsabilidade Única (SRP - Single Responsibility Principle)

Uma classe deve ter apenas um motivo para mudar, ou seja, ela deve possuir uma única responsabilidade bem definida. Isso facilita a manutenção e a evolução do sistema, evitando a sobrecarga de funcionalidades em uma única classe.

Quando estamos desenvolvendo um software, é fundamental manter nosso código simples e fácil de entender. Um dos maiores problemas surge quando colocamos várias responsabilidades em uma única classe ou módulo. O Princípio da Responsabilidade Única (SRP) nos ajuda a resolver esse tipo de situação, separando responsabilidades distintas e deixando o código mais modular e fácil de manter.

---

### Exemplo:

```cpp
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
```


-A classe Entrada é responsável apenas por obter dados.

-A classe Saida é responsável apenas por exibir dados.

-Cada classe tem uma única razão para mudar, seguindo o SRP.




## Princípio Aberto-Fechado (OCP - Open/Closed Principle)

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
```

Como o princípio foi aplicado:

-A classe Forma permite adicionar novas formas geométricas.

-Para adicionar uma nova forma, como um triângulo, basta criar uma nova classe que herde de Forma, sem modificar o código existente.

-O sistema está aberto para extensão, podemos adicionar novos tipos. Mas fechado para modificação, não precisamos alterar o que já funciona.




## Princípio da Inversão de Dependência (DIP - Dependency Inversion Principle)

Dependa de **abstrações**, não de **implementações concretas**. Este princípio sugere que as classes de alto nível não devem depender das classes de baixo nível, mas ambas devem depender de abstrações (interfaces ou classes abstratas). Isso melhora a modularidade e facilita a testabilidade.

---

###Exemplo:

```cpp
#include <iostream>

class Mensagem {
public:
    virtual void enviar() = 0;
    virtual ~Mensagem() = default;
};

class Email : public Mensagem {
public:
    void enviar() override {
        std::cout << "Enviando e-mail..." << std::endl;
    }
};

class Notificador {
    Mensagem* mensagem;
public:
    Notificador(Mensagem* m) : mensagem(m) {}
    void notificar() {
        mensagem->enviar();
    }
};

int main() {
    Email email;
    Notificador n(&email);
    n.notificar();
    return 0;
}

Como o princípio foi aplicado:

-A classe Notificador depende da interface Mensagem, e não da classe concreta Email.

-A classe Email implementa a interface Mensagem.

-Isso permite trocar Email por SMS, Push, etc., sem alterar o código de Notificador.
```

--- 


### Prefira Composição à Herança

Sempre que possível, prefira a composição (ou seja, "ter um") à herança (ou seja, "ser um"). A composição oferece maior flexibilidade e promove o desacoplamento entre os componentes, ao contrário da herança, que pode levar a uma dependência excessiva entre classes.

---

###Exemplo:

```cpp
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
```

Como o princípio foi aplicado:

-A classe Carro possui um objeto Motor, ao invés de herdar de Motor.

-Essa abordagem permite que Motor seja reutilizado em outros contextos.

-A composição reduz o acoplamento e torna o código mais flexível e fácil de manter.
