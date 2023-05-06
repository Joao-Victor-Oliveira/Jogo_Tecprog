#include <ente/menus/Menu.h>
#include <ente/menus/MenuState.h>

Menu::Menu():estado(nullptr){
    MenuState::setMenu(this);
}

Menu::~Menu(){
    estado=NULL;
}

void Menu::setEstado(MenuState* est){
    estado=est;
}

void Menu::executar(){
    while(estado){
        estado->loop();
        estado->executar();
    } 
}

void Menu::draw(){
    //não desenha
}