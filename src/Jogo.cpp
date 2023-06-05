#include <Jogo.h>
#include <stdafx.h>
#include <gerenciadores/GerenciadorGrafico.h>
using namespace Gerenciadores;
#include <ente/menus/estados/EstadoPrincipal.h>
#include <ente/entidades/inimigos/Inimigo.h>
using namespace Entidades;

Jogo::Jogo(){executar();}

Jogo::~Jogo(){}

void Jogo::executar(){
	Ente::setGG(GerenciadorGrafico::getInstance());
    Estado::setfonte("../../imagens/04B_30__.TTF");
    
    Menu testando;
    EstadoPrincipal teste;
    testando.setEstado(&teste);
    testando.executar();
}

