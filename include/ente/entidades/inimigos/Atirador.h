#pragma once
#include "Inimigo.h"
#include "../Projetil.h"

namespace Entidades{

class Atirador: public Inimigo{
    private:
    Projetil bala;
    public:
    Atirador(sf::Vector2f pos = sf::Vector2f(0.f,0.f));
    ~Atirador();

    void executar();
    void disparar(const float vel);
};

}