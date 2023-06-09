#include <ente/entidades/Projetil.h>
#include <ente/entidades/Jogador.h>
using namespace Entidades;

Projetil::Projetil(const int d,const std::string caminho, const sf::Vector2f pos,const sf::Vector2f tam,const sf::Vector2f vel):
Entidade(caminho,pos,tam),
dano(d)
{   
    velocidade = vel ;
    ativo = false;
}

Projetil::~Projetil(){  
}

void Projetil::executar(){
    move(velocidade);
    velocidade.y+= GRAVIDADE;
}

void Projetil::colid(Obstaculo* pObs,sf::Vector2f deslocamento){
    ativo = false;
}

void Projetil::colid(Jogador* pJog,sf::Vector2f deslocamento){
    ativo = false;
    pJog->danar_se(dano);
}


void Projetil::draw(){
    if(ativo && gg){
        gg->desenhar(corpo);
    }
}

void Projetil::salvar(){
    salvarPosição("../../salvamento/Projetil.txt");
}