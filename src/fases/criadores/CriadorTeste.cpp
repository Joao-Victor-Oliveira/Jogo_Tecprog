#include <fases/criadores/CriadorTeste.h>
#include <ente/entidades/inimigos/Saltador.h>
#include <ente/entidades/inimigos/Atirador.h>
#include <fases/MatrizFases.h>

using namespace Fases;

CriadorTeste::CriadorTeste(){}

CriadorTeste::~CriadorTeste(){}

void CriadorTeste::criarInimigos(Listas::ListaInimigos* li){
    add(li,new Entidades::Saltador(sf::Vector2f(200.f,200.f)));
    add(li,new Entidades::Saltador(sf::Vector2f(300.f,200.f)));
    add(li,new Entidades::Saltador(sf::Vector2f(400.f,200.f)));
    add(li,new Entidades::Saltador(sf::Vector2f(500.f,200.f)));
    printf("testando");
    add(li,new Entidades::Atirador(sf::Vector2f(600.f,200.f)));
}

void CriadorTeste::criarObstaculos(Listas::ListaObstaculos* lo){
    criarLimites(lo,mFase1);
}
