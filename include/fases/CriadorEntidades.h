#pragma once
#include <listas/ListaEntidade.h>
#include <listas/ListaObstaculos.h>
#include <ente/entidades/obstaculos/Obstaculo.h>
#include <listas/ListaEntidade.h>
namespace Fases{

class CriadorEntidades{
    private:
    int num_entidades;    
    public:
    void add(Listas::ListaEntidade<Entidades::Inimigo>* li,Entidades::Inimigo* i);
    void add(Listas::ListaObstaculos* lo,Entidades::Obstaculo* o);
    
    CriadorEntidades();
    // muito importante ser virtual, pois irei destruir por polimorfismo
    virtual ~CriadorEntidades();

    virtual void criarInimigos(Listas::ListaEntidade<Entidades::Inimigo>* li)=0;                
    virtual void criarObstaculos(Listas::ListaObstaculos* lo)=0;

    virtual void criarLimites(Listas::ListaObstaculos* lo,char fase [][41]);
};

}

