#pragma once
#include "../Estado.h"

class EstadoFases;

class EstadoPrincipal:public Estado{
    private:
    EstadoFases* pFases;
    public:
    EstadoPrincipal();
    ~EstadoPrincipal();

    void executar();
    void setTextos();
};