#include <ente/menus/estados/MenuFases.h>
#include <ente/menus/estados/MenuPrincipal.h>
#include <fases/FaseTeste.h>
#include <fases/criadores/CriadorTeste.h>
using namespace Fases;

MenuFases::MenuFases(MenuPrincipal* mp):MenuState(3),pMP(mp),pFase(NULL){
    setTextos();
}

MenuFases::~MenuFases(){if(pFase) delete pFase;}

void MenuFases::setTextos(){
    for(int i=0;i<tam;i++){
            opcoes[i]->setFont(fonte);
            opcoes[i]->setCharacterSize(40);
            opcoes[i]->setFillColor(sf::Color::White);
            opcoes[i]->setOutlineColor(sf::Color::Red);
            opcoes[i]->setPosition(sf::Vector2f(400,200+100*i));
    }

    opcoes[0]->setString("Fase teste");
    opcoes[1]->setString("Fase 2");
    opcoes[2]->setString("Voltar");
}

void MenuFases::executar(){
    switch (comando){
        case 0:
            if(pFase)
                delete pFase;
            pFase = new FaseTeste(static_cast<CriadorEntidades*> (new CriadorTeste()));
            pFase->executar();
            pFase->loop();
        break;
        case 1:
            if(pFase)
                delete pFase;
        break;
        case 2:
        if(menu)
            menu->setEstado(static_cast<MenuState*>(pMP));
        break;
    }
}