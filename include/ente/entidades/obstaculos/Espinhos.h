#pragma once

#include "Obstaculo.h"

namespace Entidades{

class Espinhos: public Obstaculo{
    private:
    const int num_espinhos; 
    sf::Sprite desenho;
    public:
    Espinhos(const int np=1,const sf::Vector2f pos = sf::Vector2f(0.f,0.f));
    ~Espinhos();

    void interagir(Jogador* pJog);
    void executar();
    void draw();
};

}

