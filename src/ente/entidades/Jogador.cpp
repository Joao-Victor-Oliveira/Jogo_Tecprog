#include <ente/entidades/Jogador.h>
#include <ente/entidades/obstaculos/Obstaculo.h>
using namespace Entidades;

Jogador::Jogador():Personagem("../../imagens/default.png",sf::Vector2f(100.f,100.f),sf::Vector2f(30.f,30.f)),
pulando(false),coliE(false),coliD(false)
{
    corpo.setFillColor(sf::Color::Green);
}

Jogador::~Jogador(){}

void Jogador::colid(Obstaculo* pObs,sf::Vector2f deslocamento){
    if(deslocamento.y<=deslocamento.x){
        if(pObs->getPosicao().y >= getPosicao().y){
            move(sf::Vector2f(0.f,deslocamento.y*-1));
            pulando = false;
        }
        else
            move(sf::Vector2f(0.f,deslocamento.y));
        velocidade.y =0.f;
    }
    else{
        if(pObs->getPosicao().x >= getPosicao().x ){
            move(sf::Vector2f(deslocamento.x*-1,0.f));
            if(deslocamento.x > 0.1)
                coliD = true;
        }
        else{
            move(sf::Vector2f(deslocamento.x,0.f));
            if(deslocamento.x > 0.1)
                coliE = true;
        }
        velocidade.x=0.f;
    }
}

void Jogador::colid(Jogador* pJog,sf::Vector2f deslocamento){
}


void Jogador::executar(){
    velocidade.x=0;
    velocidade.y+= GRAVIDADE;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if(!pulando){
            velocidade.y = -20.f;
            pulando =true;
        }
    }
    if (!coliE &&sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        velocidade.x = -10.f;
    }
    if (!coliD && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        velocidade.x = 10.f;
    }
    coliD = false; coliE= false;
    move(velocidade);
}