#include <ente/menus/estados/EstadoPause.h>



void EstadoPause::setTextos(){
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