#pragma once
#include "../Entidade.h"

namespace Entidades{

class Obstaculo: public Entidade{
    protected:
    //Jogador* jg;
    public:
    Obstaculo(const std::string s= "../../default.png",sf::Vector2f pos= sf::Vector2f(0.f,0.f),const int d=0);
    Obstaculo(sf::Vector2f pos, sf::Vector2f tam);

    virtual ~Obstaculo();

    virtual void executar();
};
}