#include <ente/entidades/Jogador.h>
#include <ente/entidades/obstaculos/Obstaculo.h>
using namespace Entidades;

#define VIDAS 10
Jogador::Jogador():Personagem("../../imagens/default.png",sf::Vector2f(100.f,100.f),sf::Vector2f(30.f,30.f)),
pulando(false),coliE(false),coliD(false)
{
    corpo.setFillColor(sf::Color::Green);
    num_vidas =VIDAS;
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
    gravidade();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if(!pulando){
            velocidade.y = -20.f;
            pulando =true;
        }
    }
    if (!coliE &&sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocidade.x = -10.f;
    }
    if (!coliD && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocidade.x = 10.f;
    }
    coliD = false; coliE= false;
    move(velocidade);
}

void Jogador::danar_se(const int dano){
    static sf::Clock relogio;

    if(relogio.getElapsedTime().asSeconds()>2 || num_vidas == VIDAS)
    {
        if(num_vidas<=0)
            printf("jog morto\n");
        num_vidas--;
        printf("jog danado\n");
        relogio.restart();
    }
}

