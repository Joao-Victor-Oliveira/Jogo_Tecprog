#include <ente/entidades/obstaculos/Plataforma.h>

using namespace Entidades;

Plataforma::Plataforma(const sf::Vector2f pos,const int cp,const int at):
Obstaculo("../../imagens/obstaculos/plataforma.png",pos,sf::Vector2f(30.f*cp,30.f*at)),
altura(at),
comprimento(cp)
{
    estatico = true;
    texture.setRepeated(true);
    plataforma_sprite.setTexture(texture);
    plataforma_sprite.setScale(sf::Vector2f(1.f, 1.f));
    plataforma_sprite.setOrigin(corpo.getSize().x / 2.f, corpo.getSize().y / 2.f);
}

Plataforma::~Plataforma(){}

void Plataforma::draw() {
    sf::Vector2f aux = corpo.getPosition();

    for (int i = 0; i < comprimento; i++) {
        for (int j = 0; j < altura; j++) {
            plataforma_sprite.setPosition(aux);
            gg->desenhar(plataforma_sprite);
            aux.y += 30;
        }
        aux.y = corpo.getPosition().y; 
        aux.x += 30; 
    }
}

void Plataforma::executar(){
    gravidade();
}