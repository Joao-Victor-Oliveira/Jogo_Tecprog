#include <ente/entidades/inimigos/Saltador.h>
#include <ente/entidades/obstaculos/Obstaculo.h>

using namespace Entidades;

#define VX 5.0

Saltador::Saltador(sf::Vector2f pos):Inimigo("../../imagens/inimigos/Saltador.png",pos,sf::Vector2f(30.f,30.f),1){
    setVelocidade(sf::Vector2f(VX*(rand()%3 -1),0.f));
}

Saltador::~Saltador(){

}

void Saltador::colid(Obstaculo* pObs){
    sf::Vector2f distanciaCentro(std::abs(getPosicao().x-pObs->getPosicao().x),std::abs(getPosicao().y-pObs->getPosicao().y));
    sf::Vector2f distanciaTamanho(std::abs(getTamanho().x-pObs->getTamanho().x)/2,std::abs(getTamanho().y-pObs->getTamanho().y)/2);
    sf::Vector2f resultante(distanciaCentro - distanciaTamanho);
    
    if(resultante.y>=resultante.x)
        velocidade.y = -17.f;
    else
        velocidade.x = velocidade.x*-1;
}

void Saltador::colid(Inimigo* pIni){
    sf::Vector2f distanciaCentro(std::abs(getPosicao().x-pIni->getPosicao().x),std::abs(getPosicao().y-pIni->getPosicao().y));
    sf::Vector2f distanciaTamanho(std::abs(getTamanho().x-pIni->getTamanho().x)/2,std::abs(getTamanho().y-pIni->getTamanho().y)/2);
    sf::Vector2f resultante(distanciaCentro - distanciaTamanho);
    
    if(resultante.y>=resultante.x)
        velocidade.y = -17.f;
    else
        velocidade.x = velocidade.x*-1;
}