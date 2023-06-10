#pragma once
#include "Lista.h"
#include <ente/entidades/Entidade.h>
#include <ente/entidades/inimigos/Inimigo.h>
#include <ente/entidades/obstaculos/Obstaculo.h>
#include <ente/entidades/Projetil.h>

namespace Listas{

    template<class TIPO>
    class ListaEntidade{
    private:
    Lista<Entidades::Entidade> entidades;
    public:
    
    ListaEntidade(){
    }
    
    ~ListaEntidade(){}

    void adicionar(TIPO* elem){
        entidades.push_back(static_cast<Entidades::Entidade*> (elem));
    }

    void remover(TIPO* elem){
        entidades.remover(static_cast<Entidades::Entidade*> (elem));
    }

    const int getTamanho(){
        return entidades.getTamanho();
    }

    TIPO* operator[](const int i){
        return static_cast<TIPO*> (entidades[i]);
    }

    void percorrer(){
        Lista<Entidades::Entidade>::Iterador it;
        it.operator=(entidades.getPrimeiro());
        while (!it.fim()) {
            Entidades::Entidade* aux = it.getConteudo();
            if(aux->getAtivo())
                aux->executar();
            ++it;
        }
    }

    void draw(){
        Lista<Entidades::Entidade>::Iterador it;
        it.operator=(entidades.getPrimeiro());
        while (!it.fim()) {
            Entidades::Entidade* aux = it.getConteudo();
            if(aux->getAtivo())
                aux->draw();
            ++it; 
        }
    }

    const bool vazia(){
        return entidades.empty();
    }

    const bool ativa(){
        Lista<Entidades::Entidade>::Iterador it;
        it.operator=(entidades.getPrimeiro());

        while (!it.fim()) {
            Entidades::Entidade* aux = it.getConteudo();
            if(aux->getAtivo())
                return 1;
            ++it;
        }
        return 0;
    }
    
    };

}