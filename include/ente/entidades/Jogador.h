#pragma once
#include "Persongem.h"

namespace Entidades{

class Jogador:public Personagem{
    private:
    static int pontos;
    static int num_vidas;
    std::string nome;
    sf::Clock relogio;
    bool pulando;
    bool coliE;
    bool coliD;
    bool danado;
    sf::Vector2f impulso;
    public:
    Jogador();
    virtual ~Jogador();

    void danar_se(const int dano);

    void colid(Obstaculo* pObs,sf::Vector2f deslocamento);
    void colid(Jogador* pJog,sf::Vector2f deslocamento);

    void executar();

    void setImpulso(const sf::Vector2f imp);
    const sf::Vector2f getImpulso()const;
    void resetImpulso();

    static void incrementarPontos(const int p);
    static const int getPontos();
    static const int getVidas();
};

}