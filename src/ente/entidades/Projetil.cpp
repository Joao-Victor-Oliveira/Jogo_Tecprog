#include <ente/entidades/Projetil.h>

using namespace Entidades;

std::vector<Projetil*>* Projetil::pVp(NULL);

Projetil::Projetil(const int d,const std::string caminho, const sf::Vector2f pos,const sf::Vector2f tam,const sf::Vector2f vel):
Entidade(caminho,pos,tam),
dano(d)
{
    velocidade = vel ;
}

Projetil::~Projetil(){
}

void Projetil::executar(){
    move(velocidade);
    velocidade.y+= GRAVIDADE;
}

void Projetil::colid(Obstaculo* pObs,sf::Vector2f deslocamento){

}

void Projetil::colid(Jogador* pJog,sf::Vector2f deslocamento){

}

void Projetil::setListaProjetil(std::vector<Projetil*>* v){pVp=v;}