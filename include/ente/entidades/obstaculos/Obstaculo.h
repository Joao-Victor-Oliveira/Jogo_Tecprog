#pragma once
#include "../Entidade.h"

namespace Entidades{

class Obstaculo: public Entidade{
    protected:
    bool solido;
    bool estatico;
    public:
    
    Obstaculo(const std::string s= "../../imagens/default.png",sf::Vector2f pos= sf::Vector2f(0.f,0.f),const sf::Vector2f tam= sf::Vector2f(0.f,0.f),const bool so=1);
    Obstaculo(sf::Vector2f pos, sf::Vector2f tam);

    virtual ~Obstaculo();

    virtual void executar();
    const bool getSolido()const;

    virtual void interagir(Jogador* pJog) =0 ;

    const bool getEstatico()const;

    virtual void colid(Obstaculo* pObs,sf::Vector2f deslocamento);
};
}