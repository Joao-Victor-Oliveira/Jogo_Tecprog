#include <ente/entidades/Jogador.h>
#include <ente/entidades/obstaculos/Obstaculo.h>
using namespace Entidades;

Jogador::Jogador():Personagem("../../imagens/default.png",sf::Vector2f(100.f,100.f),sf::Vector2f(30.f,30.f)){
    
}

Jogador::~Jogador(){}

void Jogador::colid(Obstaculo* pObs,sf::Vector2f deslocamento){
    if(deslocamento.y<=deslocamento.x){
        (velocidade.y >=0 )?move(sf::Vector2f(0.f,deslocamento.y*-1)):move(sf::Vector2f(0.f,deslocamento.y));
        velocidade.y =0.f;
    }
    else{
        (velocidade.x >=0)?move(sf::Vector2f(deslocamento.x*-1,0.f)):move(sf::Vector2f(deslocamento.x,0.f));
        velocidade.x=0.f;
    }
}

void Jogador::colid(Jogador* pJog,sf::Vector2f deslocamento){
}


void Jogador::executar(){
    velocidade.x=0;
    velocidade.y+= GRAVIDADE;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if(velocidade.y==GRAVIDADE)
            velocidade.y = -20.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        velocidade.x = -10.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        velocidade.x = 10.f;
    }
    move(velocidade);
}