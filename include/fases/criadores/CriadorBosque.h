#pragma once
#include "../CriadorEntidades.h"
#include <ente/entidades/obstaculos/Obstaculo.h>

namespace Fases{

class CriadorBosque:public CriadorEntidades{
    private:
    int num_Cookies;
    int num_Pirulitos;
    public:
    CriadorBosque();
    ~CriadorBosque();

    void criarInimigos(Listas::ListaEntidade<Entidades::Inimigo>* li);
    void criarObstaculos(Listas::ListaEntidade<Entidades::Obstaculo>* lo);

    void criarCookies(Listas::ListaEntidade<Entidades::Inimigo>* li,char fase [][41],int v[],const int n);
    void criarPirulitos(Listas::ListaEntidade<Entidades::Obstaculo>* lo,char fase [][41],int v[],const int n);
};


}