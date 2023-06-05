#include <ente/entidades/Jogador.h>
#include <ente/entidades/obstaculos/Obstaculo.h>
using namespace Entidades;

#define VIDAS 10
Jogador::Jogador():Personagem("../../imagens/Jogador.png",sf::Vector2f(100.f,100.f),sf::Vector2f(30.f,30.f)),
pulando(false),coliE(false),coliD(false),danado(false)
{
    num_vidas =VIDAS;
    corpo.setOutlineColor(sf::Color::White);
}

Jogador::~Jogador(){}

void Jogador::colid(Obstaculo* pObs,sf::Vector2f deslocamento){
    if(pObs->getSolido()){
        if(deslocamento.y-2<=deslocamento.x){
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
                move(sf::Vector2f(deslocamento.x*-1-10,0.f));
                if(deslocamento.x > 0.1)
                    coliD = true;
            }
            else{
                move(sf::Vector2f(deslocamento.x+10,0.f));
                if(deslocamento.x > 0.1)
                    coliE = true;
            }
            velocidade.x=0.f;
        }
    }

    pObs->interagir(this);
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if(!coliE)
            velocidade.x = -10.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if(!coliD)
            velocidade.x = 10.f;
    }
    coliD = false; coliE= false;
    if(danado && relogio.getElapsedTime().asSeconds()>2){
        danado=0; 
        corpo.setOutlineThickness(0);
    }
    move(velocidade);
}

void Jogador::danar_se(const int dano){
    if(relogio.getElapsedTime().asSeconds()>2 || num_vidas == VIDAS)
    {
        danado = true;
        if(num_vidas<=0)
            printf("jog morto\n");
        num_vidas--;
        relogio.restart();
        corpo.setOutlineThickness(5);
    }
}

