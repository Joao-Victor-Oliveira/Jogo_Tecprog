#pragma once
#include <ente/Ente.h>

class Estado;

class Menu:public Ente{
    private:
    Estado* estado;
    public:
    Menu();
    ~Menu();

    void setEstado(Estado* est);

    void executar();
    void draw();
};
