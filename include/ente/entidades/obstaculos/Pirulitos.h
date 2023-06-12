#pragma once

#include "Obstaculo.h"

namespace Entidades{

class Pirulitos: public Obstaculo{
    private:
    const int num_Pirulitos; 
    sf::Sprite desenho;
    public:
    Pirulitos(const int np=1,const sf::Vector2f pos = sf::Vector2f(0.f,0.f));
    ~Pirulitos();

    void interagir(Jogador* pJog);
    void executar();
    void draw();
    void salvar();
};

}

