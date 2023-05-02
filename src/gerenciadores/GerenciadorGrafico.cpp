#include "../include/gerenciadores/GerenciadorGrafico.h"
using namespace gerenciadores;
GerenciadorGrafico* GerenciadorGrafico::getInstance() {
    static GerenciadorGrafico gerenciador;
    return &gerenciador;
}

GerenciadorGrafico::GerenciadorGrafico() {
    janela.create(sf::VideoMode(1200, 800), "Jogo");
}

GerenciadorGrafico::~GerenciadorGrafico() {
    janela.close();
}

void GerenciadorGrafico::desenhar(sf::Drawable& objeto) {
    janela.draw(objeto);
}

void GerenciadorGrafico::desenhar(sf::Text& objeto) {
    janela.draw(objeto);
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
    return janela.pollEvent(evento);
}

void GerenciadorGrafico::fechar(){
    janela.close();
}