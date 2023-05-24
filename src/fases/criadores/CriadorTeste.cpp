#include <fases/criadores/CriadorTeste.h>
#include <ente/entidades/inimigos/Saltador.h>
#include <ente/entidades/obstaculos/Obstaculo.h>
#include <fases/MatrizFases.h>
using namespace Fases;

CriadorTeste::CriadorTeste(){}

CriadorTeste::~CriadorTeste(){}

void CriadorTeste::criarInimigos(Listas::ListaInimigos* li){
    add(li,new Entidades::Saltador(sf::Vector2f(200.f,200.f)));
    add(li,new Entidades::Saltador(sf::Vector2f(300.f,200.f)));
    add(li,new Entidades::Saltador(sf::Vector2f(400.f,200.f)));
    add(li,new Entidades::Saltador(sf::Vector2f(500.f,200.f)));
}

void CriadorTeste::criarObstaculos(Listas::ListaObstaculos* lo){
    add(lo,new Entidades::Obstaculo("../../imagens/plataforma.png",sf::Vector2f(1000,705),sf::Vector2f(2000,30)));
    add(lo,new Entidades::Obstaculo("../../imagens/plataforma.png",sf::Vector2f(15,1000),sf::Vector2f(30,2000)));
    add(lo,new Entidades::Obstaculo("../../imagens/plataforma.png",sf::Vector2f(1275,1000),sf::Vector2f(30,2000)));
    add(lo,new Entidades::Obstaculo("../../imagens/plataforma.png",sf::Vector2f(1000,15),sf::Vector2f(2000,30)));

    for(int i=0;i<22;i++)
        for(int j=0;j<44;j++){
            char aux = mFase1[i][j];
            if(aux == '*'){}
            else{
                if(aux == '#')
                    add(lo,new Entidades::Obstaculo("../../imagens/plataforma.png",sf::Vector2f(j*30+45,i*30+45),sf::Vector2f(30,30)));
            }
        }

/*
    add(lo,new Entidades::Obstaculo("../../imagens/plataforma.png",sf::Vector2f(300,500),sf::Vector2f(200,30)));
    add(lo,new Entidades::Obstaculo("../../imagens/plataforma.png",sf::Vector2f(300,690),sf::Vector2f(200,30)));
    add(lo,new Entidades::Obstaculo("../../imagens/plataforma.png",sf::Vector2f(500,500),sf::Vector2f(200,30)));
*/
}
