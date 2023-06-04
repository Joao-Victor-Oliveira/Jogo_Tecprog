#pragma once
#include "Obstaculo.h"

namespace Entidades{

class Plataforma:public Obstaculo{
    private:
    sf::Sprite plataforma_sprite;
    int altura;
    int comprimento;
    public:
    Plataforma(const sf::Vector2f pos = sf::Vector2f(0.f,0.f),const int cp=1,const int at=1);
    ~Plataforma();
    void draw();
    void executar();
};
   
}