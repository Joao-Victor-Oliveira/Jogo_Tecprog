#pragma once

#include <SFML/Graphics.hpp>

namespace gerenciadores{
    class GerenciadorColisao{
        private:
            Lista::ListaInimigos* listainimigos;
            Lista::ListaObstaculos* listaobstaculos;
            //talvez ter apenas 2 corpos para comparacao de colisao
            //Lista:: ListaJogador* listajogador;
        public:
            GerenciadorColisao(Lista::ListaInimigos* listainimigos, Lista::ListaObstaculos* listaobstaculos);//Lista:: ListaJogador* listajogador);
            ~GerenciadorColisao();
            const sf:: Vector2f calculaColisao(Entidades::Entidade* entd1, Entidades::Entidade* entd2);//Entidades::Entidade* entd3);
            void executar();
    };
};