#pragma once
#include "../CriadorEntidades.h"
#include <ente/entidades/obstaculos/Obstaculo.h>

namespace Fases{

class CriadorBosque:public CriadorEntidades{
    
    public:
    CriadorBosque();
    ~CriadorBosque();

    void criarInimigos(Listas::ListaEntidade<Entidades::Inimigo>* li);
    void criarObstaculos(Listas::ListaEntidade<Entidades::Obstaculo>* lo);
};


}