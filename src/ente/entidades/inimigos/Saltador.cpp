#include <ente/entidades/inimigos/Saltador.h>
#include <ente/entidades/obstaculos/Obstaculo.h>
#include <ente/entidades/Jogador.h>

using namespace Entidades;

#define VX 5.0

Saltador::Saltador(sf::Vector2f pos):Inimigo("../../imagens/inimigos/Saltador.png",pos,sf::Vector2f(30.f,30.f),1){
    setVelocidade(sf::Vector2f(VX*(rand()%3 -1),0.f));
}

Saltador::~Saltador(){

}

void Saltador::colid(Obstaculo* pObs,sf::Vector2f dmin,sf::Vector2f  d){
    sf::Vector2f resultante(d-dmin);
    if(resultante.y>=resultante.x)
        velocidade.y = -17.f;
    else
        velocidade.x = velocidade.x*-1;
}

void Saltador::colid(Inimigo* pIni,sf::Vector2f dmin,sf::Vector2f  d){
    sf::Vector2f resultante(d - dmin);
    
    if(resultante.y<=resultante.x){
        velocidade.y = -17.f;
    }
    else
        velocidade.x = velocidade.x*-1;
}

void Saltador::colid(Jogador* pJog,sf::Vector2f dmin,sf::Vector2f  d){
     sf::Vector2f resultante(d - dmin);
    
    if(resultante.y<=resultante.x){
       velocidade.y = -17.f;
    }
    else{
        velocidade.x = velocidade.x*-1;
    }
}