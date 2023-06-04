#pragma once
#include "Persongem.h"

namespace Entidades{

class Jogador:public Personagem{
    private:
    std::string nome;
    sf::Clock relogio;
    bool pulando;
    bool coliE;
    bool coliD;
    bool danado;
    public:
    Jogador();
    virtual ~Jogador();

    void danar_se(const int dano);

    void colid(Obstaculo* pObs,sf::Vector2f deslocamento);
    void colid(Jogador* pJog,sf::Vector2f deslocamento);

    void executar();
};

}