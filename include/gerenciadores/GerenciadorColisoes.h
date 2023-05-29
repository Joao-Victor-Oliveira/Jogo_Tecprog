#pragma once
#include <listas/ListaEntidade.h>
#include <listas/ListaObstaculos.h>
#include <ente/entidades/Jogador.h>
#include <ente/entidades/Projetil.h>
namespace Gerenciadores{

class GerenciadorColisoes{
    private:
    Listas::ListaEntidade<Entidades::Inimigo>* pli;
    Listas::ListaObstaculos* plo;
    std::vector<Entidades::Projetil*>* plp;
    Entidades::Jogador* pPl;
    public:
    GerenciadorColisoes(Entidades::Jogador* p=NULL);
    ~GerenciadorColisoes();
    
    void setLista(Listas::ListaEntidade<Entidades::Inimigo>* li);
    void setLista(Listas::ListaObstaculos* lo);
    void setLista(Listas::ListaEntidade<Entidades::Inimigo>* li,Listas::ListaObstaculos* lo);
    void setLista(Listas::ListaObstaculos* lo,Listas::ListaEntidade<Entidades::Inimigo>* li);
    void setProjeteis(std::vector<Entidades::Projetil*>* v);

    void colidir();

    sf::Vector2f verificaColisao(sf::Vector2f pos1,sf::Vector2f pos2,sf::Vector2f tam1,sf::Vector2f tam2);
};

}