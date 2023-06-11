#pragma once
#include "../CriadorEntidades.h"


namespace Fases{

class CriadorCastelo:public CriadorEntidades{
    private:
    int num_Fantasmas;
    int num_Gelatinas;
    public:
    CriadorCastelo();
    ~CriadorCastelo();

    void criarInimigos(Listas::ListaEntidade<Entidades::Inimigo>* li);
    void criarObstaculos(Listas::ListaEntidade<Entidades::Obstaculo>* lo);

    void criarFantasmas(Listas::ListaEntidade<Entidades::Inimigo>* li,char fase [][41],int v[],const int n);
    void criarGelatinas(Listas::ListaEntidade<Entidades::Obstaculo>* lo,char fase [][41],int v[],const int n);
};


}