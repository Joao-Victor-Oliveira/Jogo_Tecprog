#pragma once
#include <ente/Ente.h>

class MenuState;

class Menu:public Ente{
    private:
    MenuState* estado;
    public:
    Menu();
    ~Menu();

    void setEstado(MenuState* est);

    void executar();
    void draw();
};
