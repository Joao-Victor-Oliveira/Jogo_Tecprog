#include <ente/entidades/inimigos/Inimigo.h>
#include <ente/entidades/Jogador.h>

using namespace Entidades;

Inimigo::Inimigo(const std::string s,sf::Vector2f pos,const sf::Vector2f tam,const int d):
Personagem(s,pos,tam),
dano(d),
pontos(100)
{
    
}

Inimigo::~Inimigo(){

}


void Inimigo::danar_se(const int dano){
    num_vidas-=dano;
    if(num_vidas<=0){
        ativo =false;
        jogador1->incrementarPontos(pontos);
    }
}
