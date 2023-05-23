#include <ente/entidades/Jogador.h>
using namespace Entidades;

Jogador::Jogador():Personagem("../../imagens/default.png",sf::Vector2f(100.f,100.f),sf::Vector2f(30.f,30.f)){
    
}

Jogador::~Jogador(){}

void Jogador::colid(Obstaculo* pObs,sf::Vector2f dmin,sf::Vector2f  d){
    sf::Vector2f resultante(d-dmin);
    if(resultante.y>=resultante.x){
        velocidade.y = 0;
    }
    else{
        velocidade.x = 0;
    }
}

void Jogador::colid(Jogador* pJog,sf::Vector2f dmin,sf::Vector2f  d){
}


/*void Jogador::executar(){
}*/