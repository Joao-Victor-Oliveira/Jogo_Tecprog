#include <ente/menus/estados/EstadoFases.h>
#include <ente/menus/estados/EstadoPrincipal.h>
#include <fases/FaseTeste.h>
#include <fases/CasteloAssombrado.h>

using namespace Fases;

EstadoFases::EstadoFases(EstadoPrincipal* mp):Estado(3),pMP(mp),pFase(NULL){
    setTextos();
}

EstadoFases::~EstadoFases(){if(pFase) delete pFase;}

void EstadoFases::setTextos(){
    for(int i=0;i<tam;i++){
            opcoes[i]->setFont(fonte);
            opcoes[i]->setCharacterSize(40);
            opcoes[i]->setFillColor(sf::Color::White);
            opcoes[i]->setOutlineColor(sf::Color::Red);
            opcoes[i]->setPosition(sf::Vector2f(200,200+100*i));
    }

    opcoes[0]->setString("Bosque dos cookies");
    opcoes[1]->setString("Castelo assombrado");
    opcoes[2]->setString("Voltar");
}

void EstadoFases::executar(){
    switch (comando){
        case 0:
            if(pFase)
                delete pFase;
            pFase = new FaseTeste();
            pFase->executar();
            pFase->loop();
        break;
        case 1:
            if(pFase)
                delete pFase;
            pFase = new CasteloAssombrado();
            pFase->executar();
            pFase->loop();
        break;
        case 2:
        if(menu)
            menu->setEstado(static_cast<Estado*>(pMP));
        break;
    }
}
