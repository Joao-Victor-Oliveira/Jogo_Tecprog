#pragma once
#include "Inimigo.h"

namespace Entidades{

class Saltador:public Inimigo{
    private:
    float a_x;
    public:
    Saltador(sf::Vector2f pos= sf::Vector2f(0.f,0.f));
    ~Saltador();

    void colid(Obstaculo* pObs,sf::Vector2f deslocamento);
    void colid(Inimigo* pIni,sf::Vector2f deslocamento);
    void colid(Jogador* pJog,sf::Vector2f deslocamento);
};

}