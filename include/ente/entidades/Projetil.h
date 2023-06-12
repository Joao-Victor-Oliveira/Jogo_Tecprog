#pragma once
#include "Entidade.h"

namespace Entidades{

class Projetil:public Entidade{
    protected:
    const int dano;
    public:
    Projetil(const int d,const std::string caminho="../../imagens/default.png", const sf::Vector2f pos=sf::Vector2f(0.f,0.f),
    const sf::Vector2f tam= sf::Vector2f(0.f,0.f),const sf::Vector2f vel= sf::Vector2f(0.f,0.f));
    ~Projetil();

    virtual void executar();
    virtual void colid(Obstaculo* pObs,sf::Vector2f deslocamento);
    virtual void colid(Jogador* pJog,sf::Vector2f deslocamento);
        
    virtual void draw();

    bool ativo;
    void salvar();
};


}