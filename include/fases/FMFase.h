#pragma once
#include <listas/ListaInimigos.h>
#include <listas/ListaObstaculos.h>

namespace Fases{

class FMFase {
    protected:
    Listas::ListaInimigos li;
    Listas::ListaObstaculos lo;
    public:
    FMFase();
    ~FMFase();
    virtual void criarInimigos()=0;
    virtual void criarObstaculos()=0;
};

}