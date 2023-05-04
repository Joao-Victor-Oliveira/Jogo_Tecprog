#include "../../../include/ente/menus/MenuComponent.h"
    
    Menu* MenuComponent::menu = nullptr;

    MenuComponent::MenuComponent(){
    };

    MenuComponent::~MenuComponent() {

    };

    void MenuComponent::setMenu(Menu* m){
        menu=m;
    };