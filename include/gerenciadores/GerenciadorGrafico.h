#pragma once
#include <SFML/Graphics.hpp>

namespace Gerenciadores{
class GerenciadorGrafico {
public:
    static GerenciadorGrafico* getInstance();

    void desenhar(sf::Drawable& objeto);
    void desenhar(sf::Text& objeto);
    bool adicionarEvento(sf::Event& evento);


    void limpar();
    void mostrar();
    bool aberto();
    void fechar();

private:
    GerenciadorGrafico();   
    ~GerenciadorGrafico();

    sf::RenderWindow janela;
};

};
