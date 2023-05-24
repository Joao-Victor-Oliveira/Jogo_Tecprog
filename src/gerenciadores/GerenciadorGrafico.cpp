#include <gerenciadores/GerenciadorGrafico.h>
using namespace Gerenciadores;

GerenciadorGrafico* GerenciadorGrafico::getInstance() {
    static GerenciadorGrafico gerenciador;
    return &gerenciador;
}

GerenciadorGrafico::GerenciadorGrafico() {
    janela.create(sf::VideoMode(1290, 720), "Jogo");
}

GerenciadorGrafico::~GerenciadorGrafico() {
    janela.close();
}

void GerenciadorGrafico::desenhar(sf::Drawable& objeto) {
    sf::Drawable* ptr = &objeto;
    if(ptr)
        janela.draw(objeto);
    else{
        throw std::invalid_argument("evento nulo");
    }
}

void GerenciadorGrafico::desenhar(sf::Text& objeto) {
    sf::Text* ptr = &objeto;
    if(ptr)
        janela.draw(objeto);
    else{
        throw std::invalid_argument("evento nulo");
    }
}   

void GerenciadorGrafico::limpar() {
    janela.clear();
}

void GerenciadorGrafico::mostrar() {
    janela.display();
}

bool GerenciadorGrafico::aberto() {
    return janela.isOpen();
}

bool GerenciadorGrafico::adicionarEvento(sf::Event& evento) {
    sf::Event* ptr = &evento;
    if(ptr)
        return janela.pollEvent(evento);
    else{
        throw std::invalid_argument("evento nulo");
    }
}

void GerenciadorGrafico::fechar(){
    janela.close();
}