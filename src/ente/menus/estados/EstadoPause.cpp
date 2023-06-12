#include <ente/menus/estados/EstadoPause.h>

EstadoPause::EstadoPause():
Estado(3)
{
    setTextos();
}

EstadoPause::~EstadoPause(){}

void EstadoPause::setTextos(){
    for(int i=0;i<tam;i++){
            opcoes[i]->setFont(fonte);
            opcoes[i]->setCharacterSize(40);
            opcoes[i]->setFillColor(sf::Color::White);
            opcoes[i]->setOutlineColor(sf::Color::Red);
            opcoes[i]->setPosition(sf::Vector2f(400,200+100*i));
    }

    opcoes[0]->setString("voltar");
    opcoes[1]->setString("Salvar");
    opcoes[2]->setString("Sair");
}

int EstadoPause::getComando(){
    switch (comando){
        case 0:
            return 0;
        break;
        case 1:
            return 1;
        break;
        case 2:
            return 2;
        break;
    }
    return 0;
}
