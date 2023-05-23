#pragma once
#include <listas/ListaInimigos.h>
#include <listas/ListaObstaculos.h>
#include <ente/entidades/Jogador.h>

namespace Gerenciadores{

class GerenciadorColisoes{
    private:
    Listas::ListaInimigos* pli;
    Listas::ListaObstaculos* plo;
    Entidades::Jogador* pPl;
    public:
    GerenciadorColisoes(Entidades::Jogador* p=NULL);
    ~GerenciadorColisoes();
    
    void setLista(Listas::ListaInimigos* li);
    void setLista(Listas::ListaObstaculos* lo);
    void setLista(Listas::ListaInimigos* li,Listas::ListaObstaculos* lo);
    void setLista(Listas::ListaObstaculos* lo,Listas::ListaInimigos* li);

    void colidir();

    sf::Vector2f verificaColisao(sf::Vector2f pos1,sf::Vector2f pos2,sf::Vector2f tam1,sf::Vector2f tam2);
};

}