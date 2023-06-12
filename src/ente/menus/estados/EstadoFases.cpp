#include <ente/menus/estados/EstadoFases.h>
#include <ente/menus/estados/EstadoPrincipal.h>
#include <fases/BosqueDosCookies.h>
#include <fases/CasteloAssombrado.h>

using namespace Fases;

EstadoFases::EstadoFases(EstadoPrincipal* mp):Estado(4),pMP(mp),pFase(NULL){
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
    opcoes[2]->setString("Recuperar Jogo");
    opcoes[3]->setString("Voltar"); 
}

void EstadoFases::executar(){
    switch (comando){
        case 0:
            if(pFase)
                delete pFase;
            pFase = new BosqueDosCookies(0);
            pFase->executar();
            pFase->loop();
        break;
        case 1:
            if(pFase)
                delete pFase;
            pFase = new CasteloAssombrado(0);
            pFase->executar();
            pFase->loop();
        break;
        case 2:
            if(pFase)
                delete pFase;
            recuperarFase();
            pFase->executar();
            pFase->loop();   
        break;
        case 3:
        if(menu)
            menu->setEstado(static_cast<Estado*>(pMP));
        break;
    }
}


void EstadoFases::recuperarFase(){
    std::ifstream ifs("../../salvamento/Fase.txt");
    int indice=0;
    if (ifs.is_open()) {
        ifs>>indice;
        ifs.close();
    } else {
        std::cerr << "Não tem save" << std::endl;
        return;
    }
    switch (indice)
    {
    case 0:
        pFase= new BosqueDosCookies(1);
    break;
    case 1:
        pFase= new CasteloAssombrado(1);
    break;
    }
}
