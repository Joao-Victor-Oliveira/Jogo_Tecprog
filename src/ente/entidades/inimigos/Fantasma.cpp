#include <ente/entidades/inimigos/Fastasma.h>
#include <ente/entidades/Jogador.h>

using namespace Entidades;
#define VIDAS 10
Fantasma::Fantasma(sf::Vector2f pos):
Inimigo("../../imagens/inimigos/Fantasma.png",pos,sf::Vector2f(60,60),1),
aceleracao(1.2)
{
    num_vidas=VIDAS;
    pontos = 500;
}

Fantasma::~Fantasma(){}


void Fantasma::colid(Obstaculo* pObs,sf::Vector2f deslocamento){
    
}

void Fantasma::colid(Inimigo* pIni,sf::Vector2f deslocamento){
    
}

void Fantasma::colid(Jogador* pJog,sf::Vector2f deslocamento){
    if(deslocamento.y<=deslocamento.x){
        if(pJog->getPosicao().y <= getPosicao().y){
            danar_se(1);
            pJog->setVelocidade(sf::Vector2f(0.f,-18.f));
        }
        else
            pJog->danar_se(dano);
    }
    else{
        pJog->danar_se(dano);
    }
}

void Fantasma::executar(){
    gravidade();
    sf::Vector2f aux = jogador1->getPosicao();
    aux = posicao - aux;
    aux = sf::Vector2f(aux.x/sqrt(aux.x*aux.x+aux.y*aux.y),aux.y/sqrt(aux.x*aux.x+aux.y*aux.y));
    aux = aceleracao*(VIDAS+1-num_vidas)*aux;
    velocidade = aux*-1.f;
    move(velocidade);
}

void Fantasma::danar_se(const int dano){
    num_vidas -=dano;
    switch (rand()%3+1)
    {
    case 1:
        move(sf::Vector2f(400.f,0.f));
        break;
    case 2:
        move(sf::Vector2f(-400.f,0.f));
        break;
    case 3:
        move(sf::Vector2f(0.f,-400.f));
        break;
    }
    if(num_vidas<=0){
        ativo=false;
        jogador1->incrementarPontos(pontos);
    }
}

void Fantasma::salvar(){
    salvarPosição("../../salvamento/Fantasma.txt");
    salvarVidas("../../salvamento/Fantasma.txt");
}