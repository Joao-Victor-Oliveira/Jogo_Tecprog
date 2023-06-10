#include <ente/menus/estados/EstadoPrincipal.h>
#include <ente/menus/estados/EstadoFases.h>
#include <Ranking.h>

EstadoPrincipal::EstadoPrincipal():Estado(3){
    setTextos();
    pFases = new EstadoFases(this);
}

EstadoPrincipal::~EstadoPrincipal(){delete pFases;}

void EstadoPrincipal::setTextos(){
    for(int i=0;i<tam;i++){
            opcoes[i]->setFont(fonte);
            opcoes[i]->setCharacterSize(40);
            opcoes[i]->setFillColor(sf::Color::White);
            opcoes[i]->setOutlineColor(sf::Color::Red);
            opcoes[i]->setPosition(sf::Vector2f(400,200+100*i));
    }

    opcoes[0]->setString("Jogar");
    opcoes[1]->setString("Ranking");
    opcoes[2]->setString("sair");
}

void EstadoPrincipal::executar(){
    if(!menu)
        return;

    switch (comando){
        case 0:
            if(pFases)
            menu->setEstado(pFases);    
        break;
        case 1:
            mostrar();
        break;
        case 2:
            menu->setEstado(NULL);
        break;
    }
}

void EstadoPrincipal::mostrar(){
    Ranking r;
    r.mostrar();
    return;
}