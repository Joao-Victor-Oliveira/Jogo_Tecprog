#include <ente/entidades/inimigos/Saltador.h>
using namespace Entidades;

#define VX 10

Saltador::Saltador(sf::Vector2f pos):Inimigo("../../imagens/inimigos/Saltador.png",pos,1){
    setVelocidade(sf::Vector2f(0,VX));
}

Saltador::~Saltador(){

}
