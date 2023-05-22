#pragma once
#include "../Entidade.h"

namespace Entidades{

class Obstaculo: public Entidade{
    protected:
    //Jogador* jg;
    bool solido;
    public:
    Obstaculo(const std::string s= "../../imagens/default.png",sf::Vector2f pos= sf::Vector2f(0.f,0.f),const sf::Vector2f tam= sf::Vector2f(0.f,0.f),const bool so=0);
    Obstaculo(sf::Vector2f pos, sf::Vector2f tam);

    virtual ~Obstaculo();

    virtual void executar();
};
}