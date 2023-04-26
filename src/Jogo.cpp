#include <../include/Jogo.h>
#include <../include/stdafx.h>
#include <../include/gerenciadores/GerenciadorGrafico.h>
using namespace gerenciadores;

Jogo::Jogo(){executar();}

Jogo::~Jogo(){}

void Jogo::executar(){
	GerenciadorGrafico* gg = GerenciadorGrafico::getInstance();
    while(gg->aberto()){
        sf::Event evento;
                while (gg->adicionarEvento(evento))
                    if (evento.type == sf::Event::KeyPressed)
                        gg->fechar();
        printf("testeando");
    }
}

