#pragma once
#include <ente/Ente.h>
#include "CriadorEntidades.h"

namespace Fases{

class Fase:public Ente{
    protected:
    Listas::ListaInimigos listaI;
    Listas::ListaObstaculos listaO;
    public:
    Fase(CriadorEntidades* ce=NULL);
    ~Fase();
    virtual void executar();
    virtual void draw();
    virtual void loop();
};

}