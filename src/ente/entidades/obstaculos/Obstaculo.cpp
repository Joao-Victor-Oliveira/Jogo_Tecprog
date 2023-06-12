#include <ente/entidades/obstaculos/Obstaculo.h>

using namespace Entidades;

Obstaculo::Obstaculo(const std::string s,sf::Vector2f pos,const sf::Vector2f tam,const bool so):Entidade(s,pos,tam),solido(so),estatico(true){

}

Obstaculo::~Obstaculo(){}

void Obstaculo::executar(){}

const bool Obstaculo::getSolido()const{
    return solido;
}


const bool Obstaculo::getEstatico()const{
    return estatico;
}

void Obstaculo::colid(Obstaculo* pObs,sf::Vector2f deslocamento){
    if(!estatico){
        if(deslocamento.y<=deslocamento.x){
        (velocidade.y >=0 )?move(sf::Vector2f(0.f,deslocamento.y*-1)):move(sf::Vector2f(0.f,deslocamento.y));
        velocidade.y =0.f;
        }
        else{
            (velocidade.x >=0)?move(sf::Vector2f(deslocamento.x*-1,0.f)):move(sf::Vector2f(deslocamento.x,0.f));
            velocidade.x=0.f;
        }
    }
    else if(!pObs->getEstatico()){
        pObs->colid(this,deslocamento);
    }
}