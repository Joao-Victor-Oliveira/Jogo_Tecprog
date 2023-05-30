#include <ente/entidades/inimigos/Fastasma.h>
#include <ente/entidades/Jogador.h>

using namespace Entidades;

Fantasma::Fantasma(sf::Vector2f pos):
Inimigo("../../imagens/inimigos/fantasma.png",pos,sf::Vector2f(60,60),1),
aceleracao(5)
{
    corpo.setFillColor(sf::Color::Magenta);
}

Fantasma::~Fantasma(){}


void Fantasma::colid(Obstaculo* pObs,sf::Vector2f deslocamento){
    
}

void Fantasma::colid(Inimigo* pIni,sf::Vector2f deslocamento){

}

void Fantasma::colid(Jogador* pJog,sf::Vector2f deslocamento){
    
}

void Fantasma::executar(){
    sf::Vector2f aux = jogador1->getPosicao();
    aux = posicao - aux;
    aux = sf::Vector2f(aux.x/sqrt(aux.x*aux.x+aux.y*aux.y),aux.y/sqrt(aux.x*aux.x+aux.y*aux.y));
    aux = aceleracao*aux;
    velocidade = aux*-1.f;
    move(velocidade);
}