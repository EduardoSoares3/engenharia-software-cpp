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
