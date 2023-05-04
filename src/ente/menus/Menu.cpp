#include "../../../include/ente/menus/Menu.h"
#include "../../../include/ente/menus/MenuState.h"

Menu::Menu(){
    estado=NULL;
}

Menu::~Menu(){
    estado=NULL;
}

void Menu::executar(){
    try {
    if(estado)
        estado->executar(); 
    } catch(const std::exception& e) {
    std::cerr << "Erro: Menu sem Estado " << e.what() << std::endl;
    }   
}

void Menu::draw(){
    //não desenha
}