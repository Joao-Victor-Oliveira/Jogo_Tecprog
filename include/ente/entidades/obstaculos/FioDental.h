#pragma once
#include "Obstaculo.h"

namespace Entidades{

class FioDental: public Obstaculo{
    private:
    int vidas;
    public:
    FioDental(sf::Vector2f pos = sf::Vector2f(0.f,0.f));
    ~FioDental();
    void interagir(Jogador* pJog);
    void executar();
};


}