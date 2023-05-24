#pragma once
#include "../CriadorEntidades.h"

namespace Fases{

class CriadorTeste:public CriadorEntidades{
    public:
    CriadorTeste();
    ~CriadorTeste();

    void criarInimigos(Listas::ListaInimigos* li);
    void criarObstaculos(Listas::ListaObstaculos* lo);
};


}