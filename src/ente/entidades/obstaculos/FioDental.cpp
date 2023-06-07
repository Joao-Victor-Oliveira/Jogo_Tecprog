#include <ente/entidades/obstaculos/FioDental.h>
#include <ente/entidades/Jogador.h>
using namespace Entidades;

FioDental::FioDental(sf::Vector2f pos):
Obstaculo("../../imagens/obstaculos/FioDental.png",pos,sf::Vector2f(30.f,30.f),1),
vidas(rand()%3+1)
{
    estatico =false;
}

FioDental::~FioDental(){}

void FioDental::interagir(Jogador* pJog){
    pJog->operator+=(vidas);
    ativo = false;
}

void FioDental::executar(){
    move(velocidade);
    gravidade();
}