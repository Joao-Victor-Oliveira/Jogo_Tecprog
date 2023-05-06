#include <ente/menus/estados/MenuPrincipal.h>

MenuPrincipal::MenuPrincipal():MenuState(3){
    setTextos();
}

MenuPrincipal::~MenuPrincipal(){}

void MenuPrincipal::setTextos(){
    for(int i=0;i<tam;i++){
            opcoes[i]->setFont(fonte);
            opcoes[i]->setCharacterSize(40);
            opcoes[i]->setFillColor(sf::Color::White);
            opcoes[i]->setOutlineColor(sf::Color::Red);
            opcoes[i]->setPosition(sf::Vector2f(400,200+100*i));
    }

    opcoes[0]->setString("Jogar");
    opcoes[1]->setString("opcoes");
    opcoes[2]->setString("sair");
}

void MenuPrincipal::executar(){
    switch (comando){
        case 0:
        break;
        case 1:
        break;
        case 2:
        if(menu)
            menu->setEstado(NULL);
        break;
    }
}
