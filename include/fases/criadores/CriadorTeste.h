#pragma once
#include "../CriadorEntidades.h"

namespace Fases{

class CriadorTeste:public CriadorEntidades{
    public:
    CriadorTeste();
    ~CriadorTeste();

    void criarInimigos(Listas::ListaEntidade<Entidades::Inimigo>* li);
    void criarObstaculos(Listas::ListaObstaculos* lo);
};


}