#pragma once
#include "../CriadorEntidades.h"
#include <ente/entidades/obstaculos/Obstaculo.h>

namespace Fases{

class CriadorTeste:public CriadorEntidades{
    public:
    CriadorTeste();
    ~CriadorTeste();

    void criarInimigos(Listas::ListaEntidade<Entidades::Inimigo>* li);
    void criarObstaculos(Listas::ListaEntidade<Entidades::Obstaculo>* lo);
};


}