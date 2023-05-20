#include <ente/entidades/inimigos/Inimigo.h>

using namespace Entidades;

Inimigo::Inimigo(const std::string s,sf::Vector2f pos,const int d):Personagem(s,pos),dano(d){
    
}

Inimigo::~Inimigo(){

}

void Inimigo::causar_dano(){
    //implementar dps do gerenciador de colisões
}

void Inimigo::danar_se(const int dano){
    //implementar dps do gerenciador de colisões
}