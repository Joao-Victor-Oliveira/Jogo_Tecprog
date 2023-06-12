#pragma once
#include "Inimigo.h"

namespace Entidades{

class Rosquinha:public Inimigo{
    private:
    bool irritado;
    const float vx;
    public:
    Rosquinha(sf::Vector2f pos= sf::Vector2f(0.f,0.f));
    Rosquinha(sf::Vector2f pos, bool irrit);
    ~Rosquinha();

    void colid(Obstaculo* pObs,sf::Vector2f deslocamento);
    void colid(Inimigo* pIni,sf::Vector2f deslocamento);
    void colid(Jogador* pJog,sf::Vector2f deslocamento);

    void salvar();
    void setIrritado(const bool ir);
};

}