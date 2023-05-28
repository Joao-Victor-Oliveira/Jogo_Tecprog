#pragma once
#include "../Persongem.h"

namespace Entidades{
class Inimigo: public Personagem{
    protected:
    int dano;
    public:
    Inimigo(const std::string s= "../../imagens/default.png",sf::Vector2f pos= sf::Vector2f(0.f,0.f),const sf::Vector2f tam= sf::Vector2f(0.f,0.f),const int d=0);
    virtual ~Inimigo();
    virtual void causar_dano();
    virtual void danar_se(const int dano);
};
}