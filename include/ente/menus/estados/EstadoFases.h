#pragma once
#include "../Estado.h"
#include <fases/Fase.h>
class EstadoPrincipal;

class EstadoFases:public Estado{
    private:
    EstadoPrincipal* pMP; 
    Fases::Fase* pFase;
    public:
    EstadoFases(EstadoPrincipal* mp=NULL);
    ~EstadoFases();

    void executar();
    void setTextos();
};