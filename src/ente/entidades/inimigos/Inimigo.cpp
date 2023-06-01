#include <ente/entidades/inimigos/Inimigo.h>

using namespace Entidades;

Inimigo::Inimigo(const std::string s,sf::Vector2f pos,const sf::Vector2f tam,const int d):Personagem(s,pos,tam),dano(d){
    
}

Inimigo::~Inimigo(){

}


void Inimigo::danar_se(const int dano){
    num_vidas-=dano;
    if(num_vidas<=0)
        ativo =false;
}