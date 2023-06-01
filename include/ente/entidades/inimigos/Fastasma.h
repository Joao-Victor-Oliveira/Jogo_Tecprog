#pragma once 
#include "../inimigos/Inimigo.h"

namespace Entidades{

class Fantasma:public Inimigo{
    private:
    float aceleracao;
    public:
    Fantasma(sf::Vector2f pos=sf::Vector2f(0.f,0.f));
    ~Fantasma();
    
    void colid(Obstaculo* pObs,sf::Vector2f deslocamento);
    void colid(Inimigo* pIni,sf::Vector2f deslocamento);
    void colid(Jogador* pJog,sf::Vector2f deslocamento);

    void executar();

    void danar_se(const int dano);
};

}