#pragma once
#include "Inimigo.h"
#include "../Projetil.h"
#include <listas/ListaEntidade.h>

namespace Entidades{

class Cookie: public Inimigo{
    private:
    sf::Clock relogio;
    Projetil* bala;
    static Listas::ListaEntidade<Projetil>* plp;
    const int range;
    public:
    Cookie(sf::Vector2f pos = sf::Vector2f(0.f,0.f));
    ~Cookie();

    static void setListaProjetil(Listas::ListaEntidade<Projetil>* lp);

    void executar();
    void disparar(const float vel);

    void colid(Jogador* pJog,sf::Vector2f deslocamento);
    void salvar();
    void setBala(Projetil* b);
};

}