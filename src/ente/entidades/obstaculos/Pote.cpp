#include <ente/entidades/obstaculos/Pote.h>
#include <ente/entidades/Jogador.h>
using namespace Entidades;

Pote::Pote(sf::Vector2f pos):
Obstaculo("",pos,sf::Vector2f(30.f,30.f),1),
vidas(rand()%3+1)
{
    estatico =false;
    corpo.setFillColor(sf::Color::Magenta);
}

Pote::~Pote(){}

void Pote::interagir(Jogador* pJog){
    pJog->operator+=(vidas);
    ativo = false;
}

void Pote::executar(){
    move(velocidade);
    gravidade();
}