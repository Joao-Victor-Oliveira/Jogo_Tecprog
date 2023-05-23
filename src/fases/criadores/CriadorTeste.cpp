#include <fases/criadores/CriadorTeste.h>
#include <ente/entidades/inimigos/Saltador.h>
#include <ente/entidades/obstaculos/Obstaculo.h>
using namespace Fases;

CriadorTeste::CriadorTeste(){}

CriadorTeste::~CriadorTeste(){}

void CriadorTeste::criarInimigos(Listas::ListaInimigos* li){
   /* add(li,new Entidades::Saltador(sf::Vector2f(200.f,200.f)));
    add(li,new Entidades::Saltador(sf::Vector2f(300.f,200.f)));
    add(li,new Entidades::Saltador(sf::Vector2f(400.f,200.f)));
    add(li,new Entidades::Saltador(sf::Vector2f(500.f,200.f)));*/
}

void CriadorTeste::criarObstaculos(Listas::ListaObstaculos* lo){
    add(lo,new Entidades::Obstaculo("../../imagens/plataforma.png",sf::Vector2f(1000,715),sf::Vector2f(2000,30)));
    add(lo,new Entidades::Obstaculo("../../imagens/plataforma.png",sf::Vector2f(15,1000),sf::Vector2f(30,2000)));
    add(lo,new Entidades::Obstaculo("../../imagens/plataforma.png",sf::Vector2f(1265,1000),sf::Vector2f(30,2000)));

    add(lo,new Entidades::Obstaculo("../../imagens/plataforma.png",sf::Vector2f(300,500),sf::Vector2f(200,30)));
    add(lo,new Entidades::Obstaculo("../../imagens/plataforma.png",sf::Vector2f(300,700),sf::Vector2f(200,30)));
    add(lo,new Entidades::Obstaculo("../../imagens/plataforma.png",sf::Vector2f(280,500),sf::Vector2f(200,30)));
}
