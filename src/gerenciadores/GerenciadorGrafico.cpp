#include <gerenciadores/GerenciadorGrafico.h>
using namespace Gerenciadores;

GerenciadorGrafico* GerenciadorGrafico::getInstance() {
    static GerenciadorGrafico gerenciador;
    return &gerenciador;
}

GerenciadorGrafico::GerenciadorGrafico():
janela(sf::VideoMode(1290, 720), "Jogo", sf::Style::Default)
{
    sf::Vector2u phaseSize(1290, 720);

    // Redimensionar a janela para o modo de tela cheia (fullscreen) mantendo a proporção original
    sf::VideoMode fullscreenMode = sf::VideoMode::getFullscreenModes()[0];
    float scaleFactor = std::min(fullscreenMode.width / static_cast<float>(phaseSize.x),
                                 fullscreenMode.height / static_cast<float>(phaseSize.y));
    sf::Vector2u fullscreenSize(static_cast<unsigned int>(phaseSize.x * scaleFactor),
                                static_cast<unsigned int>(phaseSize.y * scaleFactor));
    janela.setSize(fullscreenSize);
    janela.setPosition(sf::Vector2i(0, 0));
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