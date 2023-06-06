#pragma once
#include "../CriadorEntidades.h"


namespace Fases{

class CriadorCastelo:public CriadorEntidades{
    
    public:
    CriadorCastelo();
    ~CriadorCastelo();

    void criarInimigos(Listas::ListaEntidade<Entidades::Inimigo>* li);
    void criarObstaculos(Listas::ListaEntidade<Entidades::Obstaculo>* lo);
};


}