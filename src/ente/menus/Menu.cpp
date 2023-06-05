#include <ente/menus/Menu.h>
#include <ente/menus/Estado.h>

Menu::Menu():estado(nullptr){
    Estado::setMenu(this);
}

Menu::~Menu(){
    estado=NULL;
}

void Menu::setEstado(Estado* est){
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