#include <Jogo.h>
#include <stdafx.h>
#include <gerenciadores/GerenciadorGrafico.h>
using namespace gerenciadores;
#include <ente/menus/estados/MenuPrincipal.h>

Jogo::Jogo(){executar();}

Jogo::~Jogo(){}

void Jogo::executar(){
	Ente::setGG(GerenciadorGrafico::getInstance());
    MenuState::setfonte("../../Lobster-Regular.ttf");
    Menu testando;
    MenuPrincipal teste;
    testando.setEstado(&teste);
    testando.executar();
}

