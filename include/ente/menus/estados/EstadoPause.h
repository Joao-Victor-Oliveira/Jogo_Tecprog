#pragma once
#include "../Estado.h"

class EstadoPause: public Estado{
    private:
    public:
    EstadoPause();
    ~EstadoPause();

    void setTextos();
    int getComando();
    void executar(){};
};