#include <ente/entidades/Projetil.h>

using namespace Entidades;

std::vector<Projetil*>* Projetil::pVp(NULL);

Projetil::Projetil(const int d,const std::string caminho, const sf::Vector2f pos,const sf::Vector2f tam,const sf::Vector2f vel):
Entidade(caminho,pos,tam),
dano(d),
ativo(false)
{
    printf("testando");
    corpo.setFillColor(sf::Color::Yellow);
    velocidade = vel ;
}

Projetil::~Projetil(){  
}

void Projetil::executar(){
    if(ativo){
    move(velocidade);
    velocidade.y+= GRAVIDADE;
    }
}

void Projetil::colid(Obstaculo* pObs,sf::Vector2f deslocamento){
    ativo = false;
    posicao = sf::Vector2f(-200.f,-200.f);
    velocidade = sf::Vector2f(0.f,0.f);
}

void Projetil::colid(Jogador* pJog,sf::Vector2f deslocamento){
    ativo = false;
}

void Projetil::setListaProjetil(std::vector<Projetil*>* v){pVp=v;}


void Projetil::draw(){
    if(ativo && gg){
        gg->desenhar(corpo);
    }
}

void Projetil::registrar(){
    pVp->push_back(this);
}