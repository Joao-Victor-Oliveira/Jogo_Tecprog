#include <fases/criadores/CriadorTeste.h>
#include <ente/entidades/inimigos/Saltador.h>
#include <ente/entidades/inimigos/Atirador.h>
#include <ente/entidades/inimigos/Fastasma.h>
#include <fases/MatrizFases.h>
#include <ente/entidades/obstaculos/Pote.h>
#include <ente/entidades/obstaculos/Espinhos.h>

using namespace Fases;

CriadorTeste::CriadorTeste(){}

CriadorTeste::~CriadorTeste(){}

void CriadorTeste::criarInimigos(Listas::ListaEntidade<Entidades::Inimigo>* li){
    
    add(li,new Entidades::Fantasma(sf::Vector2f(700.f,200.f)));

    add(li,new Entidades::Saltador(sf::Vector2f(200.f,200.f)));
    add(li,new Entidades::Saltador(sf::Vector2f(300.f,200.f)));
    add(li,new Entidades::Saltador(sf::Vector2f(400.f,200.f)));
    add(li,new Entidades::Saltador(sf::Vector2f(500.f,200.f)));
    
    add(li,new Entidades::Atirador(sf::Vector2f(600.f,200.f)));
    add(li,new Entidades::Atirador(sf::Vector2f(900.f,200.f)));
    
    
}

void CriadorTeste::criarObstaculos(Listas::ListaEntidade<Entidades::Obstaculo>* lo){
    add(lo,new Entidades::Pote(sf::Vector2f(1000.f,200.f)));
    criarLimites(lo,mFase1);
}
