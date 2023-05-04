#pragma once
#include "../Ente.h"

class MenuState;

class Menu:public Ente{
    private:
    MenuState* estado;
    public:
    Menu();
    ~Menu();

    void executar();
    void draw();
};
