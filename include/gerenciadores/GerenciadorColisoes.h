#pragma once
#include <listas/ListaInimigos.h>
#include <listas/ListaObstaculos.h>

namespace Gerenciadores{

class GerenciadorColisoes{
    private:
    Listas::ListaInimigos* pli;
    Listas::ListaObstaculos* plo;
    //Entidades::Jogador* pJg;
    public:
    GerenciadorColisoes();
    ~GerenciadorColisoes();
    
    void setLista(Listas::ListaInimigos* li);
    void setLista(Listas::ListaObstaculos* lo);
    void setLista(Listas::ListaInimigos* li,Listas::ListaObstaculos* lo);
    void setLista(Listas::ListaObstaculos* lo,Listas::ListaInimigos* li);

    void colidir();

};

}