#pragma once
#include <ente/Ente.h>
#include "CriadorEntidades.h"
#include <gerenciadores/GerenciadorColisoes.h>

namespace Fases{

class Fase:public Ente{
    protected:
    Listas::ListaInimigos listaI;
    Listas::ListaObstaculos listaO;
    Gerenciadores::GerenciadorColisoes* gc;
    public:
    Fase(CriadorEntidades* ce=NULL);
    virtual ~Fase();
    virtual void executar();
    virtual void draw();
    virtual void loop();
};

}