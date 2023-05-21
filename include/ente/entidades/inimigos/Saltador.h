#pragma once
#include "Inimigo.h"

namespace Entidades{

class Saltador:public Inimigo{
    private:
    float a_x;
    public:
    Saltador(sf::Vector2f pos= sf::Vector2f(0.f,0.f));
    ~Saltador();
};

}