#pragma once
#include <ente/Ente.h>
#include "CriadorEntidades.h"
#include <gerenciadores/GerenciadorColisoes.h>
#include <ente/entidades/Jogador.h>
#include <ente/entidades/Projetil.h>
namespace Fases{

class Fase:public Ente{
    protected:
    Listas::ListaEntidade<Entidades::Inimigo> listaI;
    Listas::ListaEntidade<Entidades::Obstaculo> listaO;
    Listas::ListaEntidade<Entidades::Projetil> listaP;
    Gerenciadores::GerenciadorColisoes* gc;
    Entidades::Jogador* player;
    sf::Text vidas;
    sf::Font font_vidas;
    sf::Clock relogio;
    public:
    Fase();
    virtual ~Fase();
    virtual void executar();
    virtual void draw();
    virtual void loop();
    virtual void percorrer();
    void criarEntidades(Fases::CriadorEntidades* ce);
    void encerar(const bool ganhou);
    void pontuar();
};

}