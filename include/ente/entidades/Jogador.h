#pragma once
#include "Persongem.h"

namespace Entidades{

class Jogador:public Personagem{
    private:
    std::string nome;
    bool pulando;
    bool coliE;
    bool coliD;
    public:
    Jogador();
    virtual ~Jogador();

    void colid(Obstaculo* pObs,sf::Vector2f deslocamento);
    void colid(Jogador* pJog,sf::Vector2f deslocamento);

    void executar();
};

}