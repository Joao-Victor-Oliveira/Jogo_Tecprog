#include <ente/entidades/obstaculos/Obstaculo.h>

using namespace Entidades;

Obstaculo::Obstaculo(const std::string s,sf::Vector2f pos,const sf::Vector2f tam,const bool so):Entidade(s,pos,tam),solido(so){
    corpo.setFillColor(sf::Color::White);
}

Obstaculo::~Obstaculo(){}

void Obstaculo::executar(){}
