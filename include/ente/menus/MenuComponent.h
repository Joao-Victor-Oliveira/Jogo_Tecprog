#pragma once
#include "../Ente.h"
#include "Menu.h"

class MenuComponent:public Ente{
    protected:
    static Menu* menu;
    public:
    MenuComponent();
    virtual ~MenuComponent();

    static void setMenu(Menu* m);

    virtual void draw()=0;
    virtual void executar() = 0;
};