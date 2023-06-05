#pragma once
#include "Inimigo.h"
#include "../Projetil.h"
#include <listas/ListaEntidade.h>

namespace Entidades{

class Atirador: public Inimigo{
    private:
    sf::Clock relogio;
    Projetil* bala;
    static Listas::ListaEntidade<Entidades::Projetil>* plp;
    const int range;
    public:
    Atirador(sf::Vector2f pos = sf::Vector2f(0.f,0.f));
    ~Atirador();

    static void setListaProjetil(Listas::ListaEntidade<Entidades::Projetil>* lp);

    void executar();
    void disparar(const float vel);

    void colid(Jogador* pJog,sf::Vector2f deslocamento);
};

}