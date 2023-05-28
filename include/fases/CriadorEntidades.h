#pragma once
#include <listas/ListaInimigos.h>
#include <listas/ListaObstaculos.h>
#include <ente/entidades/obstaculos/Obstaculo.h>

namespace Fases{

class CriadorEntidades{
    private:
    int num_entidades;    
    public:
    void add(Listas::ListaInimigos* li,Entidades::Inimigo* i);
    void add(Listas::ListaObstaculos* lo,Entidades::Obstaculo* o);
    
    CriadorEntidades();
    // muito importante ser virtual, pois irei destruir por polimorfismo
    virtual ~CriadorEntidades();

    virtual void criarInimigos(Listas::ListaInimigos* li)=0;                
    virtual void criarObstaculos(Listas::ListaObstaculos* lo)=0;

    virtual void criarLimites(Listas::ListaObstaculos* lo,char fase [][41]);
};

}

