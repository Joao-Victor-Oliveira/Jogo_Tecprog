#include <ente/entidades/Persongem.h>
using namespace Entidades;

Personagem::Personagem(const std::string s,const sf::Vector2f pos,const sf::Vector2f tam):Entidade(s,pos,tam),num_vidas(3){

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

void Personagem::colid(Obstaculo* pObs,sf::Vector2f dmin,sf::Vector2f  d){}
void Personagem::colid(Inimigo* pIni,sf::Vector2f dmin,sf::Vector2f  d){}
void Personagem::colid(Jogador* pJog,sf::Vector2f dmin,sf::Vector2f  d){}