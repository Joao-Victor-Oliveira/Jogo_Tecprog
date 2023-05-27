#include <ente/entidades/inimigos/Saltador.h>
#include <ente/entidades/obstaculos/Obstaculo.h>
#include <ente/entidades/Jogador.h>

using namespace Entidades;

#define VX 5.0

Saltador::Saltador(sf::Vector2f pos):Inimigo("../../imagens/inimigos/Saltador.png",pos,sf::Vector2f(30.f,30.f),1){
    (rand()%2)?setVelocidade(sf::Vector2f(VX,0.f)):setVelocidade(sf::Vector2f(-1*VX,0.f));
}

Saltador::~Saltador(){

}

void Saltador::colid(Obstaculo* pObs,sf::Vector2f deslocamento){
    if(deslocamento.y<=deslocamento.x){
        if(pObs->getPosicao().y >= getPosicao().y){
            move(sf::Vector2f(0.f,deslocamento.y*-1));
            velocidade.y =-17.f;
        }
        else{
            move(sf::Vector2f(0.f,deslocamento.y));
            velocidade.y =5.f;
        }
    }
    else{
        (velocidade.x >=0)?move(sf::Vector2f(deslocamento.x*-1,0.f)):move(sf::Vector2f(deslocamento.x,0.f));
        velocidade.x *= -1;
    }
}

void Saltador::colid(Inimigo* pIni,sf::Vector2f deslocamento){

    if(deslocamento.y<=deslocamento.x){
        if(velocidade.y >=0 ){
            move(sf::Vector2f(0.f,deslocamento.y*-1));
            velocidade.y =-17.f;
        }
        else{
            move(sf::Vector2f(0.f,deslocamento.y));
            velocidade.y =8.f;
        }
    }
    else{
        (velocidade.x >=0)?move(sf::Vector2f(deslocamento.x*-1,0.f)):move(sf::Vector2f(deslocamento.x,0.f));
        velocidade.x *= -1;
    }
}

void Saltador::colid(Jogador* pJog,sf::Vector2f deslocamento){
    if(deslocamento.y<=deslocamento.x){
        if(posicao.y < pJog->getPosicao().y){
            move(sf::Vector2f(0.f,deslocamento.y*-1));
            velocidade.y =-17.f;
        }
        else{
            move(sf::Vector2f(0.f,deslocamento.y));
            velocidade.y =8.f;
        }
    }
    else{
        (velocidade.x >=0)?move(sf::Vector2f(deslocamento.x*-1,0.f)):move(sf::Vector2f(deslocamento.x,0.f));
        velocidade.x *= -1;
    }
}