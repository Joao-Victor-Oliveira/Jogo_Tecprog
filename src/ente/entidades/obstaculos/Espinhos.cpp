#include <ente/entidades/obstaculos/Espinhos.h>
#include <ente/entidades/Jogador.h>

using namespace Entidades;

Espinhos::Espinhos(const int np,const sf::Vector2f pos):
Obstaculo("../../imagens/obstaculos/espinho.png",pos,sf::Vector2f(np*15,30),true),
num_espinhos(np)
{       
    texture.setRepeated(true);
    desenho.setTexture(texture);
    desenho.setScale(sf::Vector2f(1.f, 1.f));
    desenho.setOrigin(corpo.getSize().x / 2.f, corpo.getSize().y / 2.f);
    
    estatico =0;
}   

Espinhos::~Espinhos(){

}

void Espinhos::interagir(Jogador* pJog){
    pJog->danar_se(1);
}

void Espinhos::executar(){
    move(velocidade);
    gravidade();
}

void Espinhos::draw(){
    sf::Vector2f aux = corpo.getPosition();
    desenho.setPosition(aux);

    for(int i=0;i<num_espinhos;i++){
        gg->desenhar(desenho);
        aux.x += 15;
        desenho.setPosition(aux);
    }
}