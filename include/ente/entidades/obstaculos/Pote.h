#pragma once
#include "Obstaculo.h"

namespace Entidades{

class Pote: public Obstaculo{
    private:
    int vidas;
    public:
    Pote(sf::Vector2f pos = sf::Vector2f(0.f,0.f));
    ~Pote();
    void interagir(Jogador* pJog);
    void executar();
};


}