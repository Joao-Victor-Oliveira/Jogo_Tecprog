#include <ente/entidades/Persongem.h>
using namespace Entidades;

Personagem::Personagem(const std::string s,const sf::Vector2f pos):Entidade(s,pos),num_vidas(3){

}

Personagem::~Personagem(){
    
}

void Personagem::operator+=(const int num){
    num_vidas+=num;
}

void Personagem::operator-=(const int num){
    num_vidas-=num;
}

const int Personagem::getVidas(){
    return num_vidas;
}

void Personagem::atacar(){
    //nada por enquanto
}

void Personagem::danar_se(const int dano){
    num_vidas-=1;
}