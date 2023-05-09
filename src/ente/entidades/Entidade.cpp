#include <ente/entidades/Entidade.h>

Entidade::Entidade(std::string caminho="", float px, float py):velocidade(0.f,0.f),posicao(px,py){

sf::Vector2f()
}

Entidade::~Entidade(){}
    
void Entidade::setVelocidade(sf::Vector2f vel){velocidade = vel;}
void Entidade::setPosicao(sf::Vector2f pos){posicao=pos;}

const sf::Vector2f Entidade::getVelocidade()const{return velocidade;}
const sf::Vector2f Entidade::getPosicao()const{return posicao;}

void Entidade::executar(){posicao+=velocidade;}
void Entidade::draw(){gg->desenhar(corpo);}