#pragma once
#include "Entidade.h"


namespace Entidades{
class Obstaculo;
class Jogador;
class Inimigo;

class Personagem: public Entidade{
    protected:
    int num_vidas;
    
    public:
    Personagem(const std::string s="",const sf::Vector2f pos=sf::Vector2f(0.f,0.f));
    ~Personagem();

    void operator+=(const int num);
    void operator-=(const int num);
    const int getVidas();

    virtual void atacar();
    virtual void danar_se(const int dano);

    virtual void colid(Obstaculo* pObs);
    virtual void colid(Inimigo* pIni);
    virtual void colid(Jogador* pJog);
};

}