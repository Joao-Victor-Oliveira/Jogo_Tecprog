#pragma once
#include <ente/Ente.h>
#include "CriadorEntidades.h"
#include <gerenciadores/GerenciadorColisoes.h>
#include <ente/entidades/Jogador.h>
namespace Fases{

class Fase:public Ente{
    protected:
    Listas::ListaInimigos listaI;
    Listas::ListaObstaculos listaO;
    Gerenciadores::GerenciadorColisoes* gc;
    Entidades::Jogador* player;
    public:
    Fase(CriadorEntidades* ce=NULL);
    virtual ~Fase();
    virtual void executar();
    virtual void draw();
    virtual void loop();
};

}